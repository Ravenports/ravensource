--- m68kcpu.h.orig	2024-06-06 15:45:53 UTC
+++ m68kcpu.h
@@ -75,7 +75,7 @@
 
 
 //Para haiku
-#ifdef HAIKU_OS
+#if defined HAIKU_OS || defined __DragonFly__
 typedef unsigned int uint;
 
 #else
