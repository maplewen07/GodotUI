# Runtime Model

The runtime flow is:

```text
Service -> Controller -> ViewModelStore -> Binder -> Control
Control signal -> generated View handler -> Controller -> Store
```

Lifecycle operations use `ManifestUiHandle`:

- `PreloadAsync`: retain the package scene resource without instantiating it.
- `OpenAsync`: load, instantiate, initialize, bind, flush, and activate an instance.
- `HideAsync`: remove an instance from the active layer while preserving its Controller and Store.
- `ShowAsync`: reactivate a hidden instance and apply missed Store revisions.
- `CloseAsync`: close and dispose one instance.
- `ReleaseAsync`: release package preload and eligible package-scoped state.

Controller scopes:

- `Instance`: one Controller and Store per UI instance. Prefer this for new packages.
- `Screen`: reuse by package and instance key.
- `Package`: share state across package instances. Use only when shared state is intentional.

Services are registered on the Manifest UI manager and resolved by Controllers. Message envelopes carry channel, scope, sender, event id, and Variant payload. Localization uses a package TranslationDomain so identical keys in different packages do not collide.
