# Inventory Example

Inventory is a schema version 1 package demonstrating:

- an instance-scoped, partial Controller;
- a keyed `IInventoryService` declared in `codegen.json`;
- deferred Store updates and batching;
- a pooled list repeater with item bindings;
- filter input and a refresh event;
- localized static copy and dynamic summary/capacity bindings.

## Run

Install the matching Manifest UI addon at `addons/manifest_ui/`, then run:

```powershell
manifest-ui validate ui/inventory/package.json
manifest-ui generate ui/inventory/package.json
manifest-ui generate ui/inventory/package.json --check
manifest-ui verify ui/inventory/package.json
dotnet build
```

Generation creates the `InventoryService` Controller accessor. `Main.cs`
registers `DemoInventoryService` with the matching `demo` key before it opens
`example.inventory`.

The repeater uses `sku` as stable identity and retains up to 16 pooled row
controls. It does not claim viewport virtualization.
