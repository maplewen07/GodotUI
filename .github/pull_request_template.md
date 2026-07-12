## Summary

Describe the user-visible or engineering outcome.

## Verification

List the exact commands and scenarios tested.

## Compatibility

Describe Manifest schema, public API, generated output, or migration impact. Use
`None` when the change has no compatibility effect.

## Checklist

- [ ] Tests cover the changed behavior.
- [ ] `pwsh ./scripts/ci/Invoke-CI.ps1` passes.
- [ ] Generated commands leave tracked files unchanged.
- [ ] User-visible changes are recorded in `CHANGELOG.md`.
- [ ] New third-party material has compatible licensing and a notice.
