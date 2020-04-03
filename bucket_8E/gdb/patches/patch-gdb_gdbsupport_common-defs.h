--- gdb/gdbsupport/common-defs.h.orig	2020-02-08 12:50:14 UTC
+++ gdb/gdbsupport/common-defs.h
@@ -55,9 +55,15 @@
 
    Must do this before including any system header, since other system
    headers may include stdint.h/inttypes.h.  */
+#ifndef __STDC_CONSTANT_MACROS
 #define __STDC_CONSTANT_MACROS 1
+#endif
+#ifndef __STDC_LIMIT_MACROS
 #define __STDC_LIMIT_MACROS 1
+#endif
+#ifndef __STDC_FORMAT_MACROS
 #define __STDC_FORMAT_MACROS 1
+#endif
 
 /* Some distros enable _FORTIFY_SOURCE by default, which on occasion
    has caused build failures with -Wunused-result when a patch is
