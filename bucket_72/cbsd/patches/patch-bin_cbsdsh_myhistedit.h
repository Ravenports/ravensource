--- bin/cbsdsh/myhistedit.h.orig	2025-06-15 22:34:21 UTC
+++ bin/cbsdsh/myhistedit.h
@@ -32,15 +32,7 @@
  * $FreeBSD: head/bin/sh/myhistedit.h 326025 2017-11-20 19:49:47Z pfg $
  */
 
-#ifdef CBSD
-#ifdef __DragonFly__
 #include <histedit.h>
-#else
-#include "/usr/include/histedit.h"
-#endif
-#else
-#include <histedit.h>
-#endif
 
 extern History *hist;
 extern EditLine *el;
