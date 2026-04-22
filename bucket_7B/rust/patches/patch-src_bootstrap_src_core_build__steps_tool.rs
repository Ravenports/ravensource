--- src/bootstrap/src/core/build_steps/tool.rs.orig	2026-04-14 19:55:32 UTC
+++ src/bootstrap/src/core/build_steps/tool.rs
@@ -710,6 +710,57 @@ impl Step for Rustdoc {
         }
 
         // If stage is higher, we build rustdoc instead
+        // Ravenports: Identify duplicate rmeta/so files for compiler crates and delete the oldest.
+        let triple_str = target.rustc_target_arg();
+        let stage0_sysroot = builder.out.join(triple_str).join("stage0-sysroot");
+        let target_libdir = stage0_sysroot.join("lib/rustlib").join(triple_str).join("lib");
+
+        if target_libdir.exists() {
+            if let Ok(entries) = fs::read_dir(&target_libdir) {
+                let mut rmeta_files: Vec<(String, std::path::PathBuf, std::time::SystemTime)> = Vec::new();
+                for entry in entries.flatten() {
+                    let path = entry.path();
+                    let file_name = path.file_name().and_then(|s| s.to_str()).unwrap_or("");
+                    let ext = path.extension().and_then(|s| s.to_str()).unwrap_or("");
+
+                    // Target compiler crates, protecting foundational infra.
+                    // We check for .rmeta AND .so to handle dylib duplicates (driver/macros).
+                    if file_name.starts_with("librustc_") && 
+                       !file_name.starts_with("librustc_demangle") && 
+                       !file_name.starts_with("librustc_std_workspace") &&
+                       !file_name.starts_with("librustc_literal_escaper") &&
+                       !file_name.starts_with("librustc_hash") &&
+                       (ext == "rmeta" || ext == "so")
+                    {
+                        if let Ok(metadata) = fs::metadata(&path) {
+                            if let Ok(mtime) = metadata.modified() {
+                                rmeta_files.push((file_name.to_string(), path, mtime));
+                            }
+                        }
+                    }
+                }
+
+                rmeta_files.sort_by(|a, b| a.0.cmp(&b.0));
+
+                let mut i = 1;
+                while i < rmeta_files.len() {
+                    let prefix_curr = rmeta_files[i].0.split('-').next().unwrap_or("");
+                    let prefix_prev = rmeta_files[i-1].0.split('-').next().unwrap_or("");
+
+                    if !prefix_curr.is_empty() && prefix_curr == prefix_prev {
+                        let to_delete_idx = if rmeta_files[i].2 > rmeta_files[i-1].2 { i - 1 } else { i };
+                        let (_, ref path, _) = rmeta_files[to_delete_idx];
+                        builder.info(&format!("Ravenports: deleting oldest duplicate: {}", rmeta_files[to_delete_idx].0));
+                        let _ = fs::remove_file(path);
+                        rmeta_files.remove(to_delete_idx);
+                        // Don't increment i; check the same index again against the new neighbor
+                    } else {
+                        i += 1;
+                    }
+                }
+            }
+        }
+
         let bin_rustdoc = || {
             let sysroot = builder.sysroot(target_compiler);
             let bindir = sysroot.join("bin");
