--- src/fg_internal.h.orig	2022-10-07 16:12:51 UTC
+++ src/fg_internal.h
@@ -137,9 +137,6 @@
  * If so, perhaps there should be a config_guess.h for them. Alternatively,
  * config guesses could be placed above, just after the config.h exclusion.
  */
-#if defined(__FreeBSD__) || defined(__NetBSD__)
-#    define HAVE_USB_JS 1
-#endif
 
 #if defined(_MSC_VER) || defined(__WATCOMC__)
 /* strdup() is non-standard, for all but POSIX-2001 */
