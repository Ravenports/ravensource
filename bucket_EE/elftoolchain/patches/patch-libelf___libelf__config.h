--- libelf/_libelf_config.h.orig	2015-02-24 19:17:47 UTC
+++ libelf/_libelf_config.h
@@ -26,7 +26,7 @@
  * $Id: _libelf_config.h 3168 2015-02-24 19:17:47Z emaste $
  */
 
-#if defined(__APPLE__) || defined(__DragonFly__)
+#if defined(__APPLE__) || defined(__DragonFly__) || defined(__sun__)
 
 #if	defined(__amd64__)
 #define	LIBELF_ARCH		EM_X86_64
