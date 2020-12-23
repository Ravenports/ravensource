--- test/dlwrap.c.orig	2020-12-22 14:41:49 UTC
+++ test/dlwrap.c
@@ -34,6 +34,8 @@
 
 /* dladdr is a glibc extension */
 #define _GNU_SOURCE
+/* FreeBSD needs this to make asprintf() and dlvsym() visible */
+#define __BSD_VISIBLE 1
 #include <dlfcn.h>
 
 #include <stdbool.h>
@@ -213,6 +215,10 @@ dlsym(void *handle, const char *name)
 void *
 dlwrap_real_dlsym(void *handle, const char *name)
 {
+#ifdef __sun__
+    fprintf(stderr, "dlwrap_real_dlsym unsupported on SunOS (missing dlvsym)");
+    exit(1);
+#else
     static fips_dlsym_t real_dlsym = NULL;
 
     if (!real_dlsym) {
@@ -275,6 +281,7 @@ dlwrap_real_dlsym(void *handle, const ch
     }
 
     return real_dlsym(handle, name);
+#endif
 }
 
 void *
