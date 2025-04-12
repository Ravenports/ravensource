--- deps/cares/config/netbsd/ares_config.h.orig	2025-04-01 09:34:05 UTC
+++ deps/cares/config/netbsd/ares_config.h
@@ -119,7 +119,7 @@
 /* #undef HAVE_GETRANDOM */
 
 /* Define to 1 if you have `getservbyport_r` */
-#define HAVE_GETSERVBYPORT_R 1
+/* #undef HAVE_GETSERVBYPORT_R */ 
 
 /* Define to 1 if you have `gettimeofday` */
 #define HAVE_GETTIMEOFDAY 1
@@ -580,4 +580,4 @@
 /* #undef __MINGW_USE_VC2005_COMPAT */
 
 /* Define as 'unsigned int' if <stddef.h> doesn't define. */
-/* #undef size_t */
\ No newline at end of file
+/* #undef size_t */
