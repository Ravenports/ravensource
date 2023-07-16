# Since 1.70.0 upgrade this fails to build with gold:
version script assignment of  to symbol __rust_alloc_error_handler_should_panic failed: symbol not defined

Connected with patches:
patch-library_alloc_src_alloc.rs
patch-library_std_src_alloc.rs

Essentially zoom has been disabled -- out-of-memory always panics with these patches

--- compiler/rustc_codegen_ssa/src/back/symbol_export.rs.orig	2023-07-12 03:32:40 UTC
+++ compiler/rustc_codegen_ssa/src/back/symbol_export.rs
@@ -233,15 +233,6 @@ fn exported_symbols_provider_local(
             ));
         }
 
-        symbols.push((
-            ExportedSymbol::NoDefId(SymbolName::new(tcx, OomStrategy::SYMBOL)),
-            SymbolExportInfo {
-                level: SymbolExportLevel::Rust,
-                kind: SymbolExportKind::Text,
-                used: false,
-            },
-        ));
-
         let exported_symbol =
             ExportedSymbol::NoDefId(SymbolName::new(tcx, NO_ALLOC_SHIM_IS_UNSTABLE));
         symbols.push((
