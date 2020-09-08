Don't hardcode STRIP unconditionally.  Instead, respect the build
environment's settings.

--- build/top.mk.orig	2020-09-07 15:13:36 UTC
+++ build/top.mk
@@ -59,8 +59,6 @@ INSTALL_PROGRAM = $(INSTALL)
 INSTALL_DATA = $(INSTALL) -m 644
 INSTALL_SCRIPT = $(INSTALL)
 
-STRIP = -s
-
 LINT = lint
 5LINT = 5lint
 
