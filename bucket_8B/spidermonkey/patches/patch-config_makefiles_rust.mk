--- ../../config/makefiles/rust.mk.orig	2020-07-08 11:51:15 UTC
+++ ../../config/makefiles/rust.mk
@@ -61,7 +61,7 @@ ifndef MOZ_DEBUG_RUST
 # Enable link-time optimization for release builds, but not when linking
 # gkrust_gtest.
 ifeq (,$(findstring gkrust_gtest,$(RUST_LIBRARY_FILE)))
-cargo_rustc_flags += -Clto
+do_nada =
 endif
 endif
 endif
