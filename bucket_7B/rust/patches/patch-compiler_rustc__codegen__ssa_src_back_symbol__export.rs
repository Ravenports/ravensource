# Since 1.70.0 upgrade this fails to build with gold:
version script assignment of  to symbol __rust_alloc_error_handler_should_panic failed: symbol not defined

Connected with patches:
patch-library_alloc_src_alloc.rs
patch-library_std_src_alloc.rs

Essentially zoom has been disabled -- out-of-memory always panics with these patches

--- compiler/rustc_codegen_ssa/src/back/symbol_export.rs.orig	2023-05-31 19:28:10 UTC
+++ compiler/rustc_codegen_ssa/src/back/symbol_export.rs
@@ -232,15 +232,6 @@ fn exported_symbols_provider_local(
                 },
             ));
         }
-
-        symbols.push((
-            ExportedSymbol::NoDefId(SymbolName::new(tcx, OomStrategy::SYMBOL)),
-            SymbolExportInfo {
-                level: SymbolExportLevel::Rust,
-                kind: SymbolExportKind::Text,
-                used: false,
-            },
-        ));
     }
 
     if tcx.sess.instrument_coverage() || tcx.sess.opts.cg.profile_generate.enabled() {
