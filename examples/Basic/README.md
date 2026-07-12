# Basic Example

Basic is a minimal schema version 1 package demonstrating:

- an instance-scoped Controller;
- localized title, hint, and button text;
- immediate Store updates;
- a two-way `LineEdit` input;
- binding fallbacks and number formatting;
- a generated button event and message channel.

## Run

Install the matching Manifest UI addon at `addons/manifest_ui/`, then run:

```powershell
manifest-ui validate ui/basic/package.json
manifest-ui generate ui/basic/package.json
manifest-ui generate ui/basic/package.json --check
manifest-ui verify ui/basic/package.json
dotnet build
```

Open this directory in Godot 4.7 Mono and run the project. The generated catalog
is registered by `Main.cs`, which opens `example.basic` by package id.

Change `TranslationServer` locale to `zh_CN` at runtime or in a debugger to see
the package TranslationDomain update static copy.
