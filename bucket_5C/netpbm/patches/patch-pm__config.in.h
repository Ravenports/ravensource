Remove bogus SYSV section (fixes build on SunOS)

--- pm_config.in.h.orig	2025-09-27 20:56:22 UTC
+++ pm_config.in.h
@@ -74,7 +74,7 @@
 ** for the format of the color database file.
 */
 
-#if (defined(SYSV) || defined(__amigaos__))
+#if defined(__amigaos__)
 
 #include <string.h>
 
