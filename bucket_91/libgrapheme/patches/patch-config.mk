--- config.mk.orig	2025-12-24 07:21:23 UTC
+++ config.mk
@@ -23,7 +23,7 @@ BUILD_CFLAGS   = $(CFLAGS)
 BUILD_LDFLAGS  = $(LDFLAGS)
 
 SHFLAGS   = -fPIC -ffreestanding
-SOFLAGS   = -shared -nostdlib -Wl,--soname=libgrapheme.so.$(VERSION_MAJOR).$(VERSION_MINOR)
+SOFLAGS   = -shared -nostdlib -Wl,-soname,libgrapheme.so.$(VERSION_MAJOR).$(VERSION_MINOR)
 SOSYMLINK = true
 
 # tools (unset $LDCONFIG to not call ldconfig(1) after install/uninstall)
