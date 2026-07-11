#!/usr/bin/env python3
"""Validate a Manifest UI package with the release CLI or repository fallback."""

from __future__ import annotations

import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys


REFERENCE_KEYS = ("assets", "layout", "bindings", "codegen", "validation", "strings")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--project", default=".", help="Godot project directory")
    parser.add_argument("--package", required=True, help="Package manifest path")
    return parser.parse_args()


def load_json(path: Path) -> dict:
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except FileNotFoundError:
        raise ValueError(f"Missing file: {path}") from None
    except json.JSONDecodeError as error:
        raise ValueError(f"Invalid JSON in {path}:{error.lineno}:{error.colno}: {error.msg}") from error
    if not isinstance(value, dict):
        raise ValueError(f"Expected a JSON object: {path}")
    return value


def preflight(project: Path, package_path: Path) -> None:
    if not (project / "project.godot").is_file():
        raise ValueError(f"project.godot was not found under {project}")

    package = load_json(package_path)
    if package.get("schemaVersion") != 1:
        raise ValueError(f"Expected schemaVersion 1 in {package_path}")

    package_dir = package_path.parent
    for key in REFERENCE_KEYS:
        reference = package.get(key)
        if reference is None and key == "strings":
            continue
        if not isinstance(reference, str) or not reference.strip():
            raise ValueError(f"Missing package reference '{key}' in {package_path}")
        referenced_path = (package_dir / reference).resolve()
        if package_dir.resolve() not in (referenced_path, *referenced_path.parents):
            raise ValueError(f"Package reference '{key}' escapes the package directory")
        load_json(referenced_path)


def find_command(project: Path, package_path: Path) -> list[str]:
    configured = os.environ.get("MANIFEST_UI_CLI")
    if configured:
        return [configured, "validate", str(package_path), "--format", "text"]

    installed = shutil.which("manifest-ui")
    if installed:
        return [installed, "validate", str(package_path), "--format", "text"]

    cli_project = project / "tools" / "ManifestUi.Cli" / "ManifestUi.Cli.csproj"
    if cli_project.is_file():
        return [
            "dotnet",
            "run",
            "--project",
            str(cli_project),
            "--",
            "validate",
            str(package_path),
            "--format",
            "text",
        ]

    legacy_project = project / "tools" / "ManifestUiGen" / "ManifestUiGen.csproj"
    if legacy_project.is_file():
        return [
            "dotnet",
            "run",
            "--project",
            str(legacy_project),
            "--",
            "validate",
            str(package_path),
        ]

    raise ValueError("Manifest UI CLI was not found. Install the CLI or run from the GodotUI repository.")


def main() -> int:
    args = parse_args()
    project = Path(args.project).resolve()
    package_path = Path(args.package)
    if not package_path.is_absolute():
        package_path = (project / package_path).resolve()

    try:
        preflight(project, package_path)
        command = find_command(project, package_path)
    except ValueError as error:
        print(f"ERROR: {error}", file=sys.stderr)
        return 2

    completed = subprocess.run(command, cwd=project, check=False)
    return completed.returncode


if __name__ == "__main__":
    raise SystemExit(main())
