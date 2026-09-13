--- make/autoconf/flags-ldflags.m4.orig	2024-04-29 14:34:19 UTC
+++ make/autoconf/flags-ldflags.m4
@@ -75,7 +75,7 @@ AC_DEFUN([FLAGS_SETUP_LDFLAGS_HELPER],
       fi
     fi
 
-    BASIC_LDFLAGS_JVM_ONLY=""
+    BASIC_LDFLAGS_JVM_ONLY="-Wl,--undefined-version"
 
   elif test "x$TOOLCHAIN_TYPE" = xclang; then
     BASIC_LDFLAGS_JVM_ONLY="-mno-omit-leaf-frame-pointer -mstack-alignment=16 \
