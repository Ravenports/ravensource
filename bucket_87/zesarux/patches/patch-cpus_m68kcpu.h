--- cpus/m68kcpu.h.orig	2026-06-09 16:37:08 UTC
+++ cpus/m68kcpu.h
@@ -75,7 +75,7 @@
 
 
 //Para haiku
-#ifdef HAIKU_OS
+#if defined(HAIKU_OS) || defined(__DragonFly__)
 typedef unsigned int uint;
 
 #else
