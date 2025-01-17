--- cpus/m68kcpu.h.orig	2025-01-16 17:27:12 UTC
+++ cpus/m68kcpu.h
@@ -75,7 +75,7 @@
 
 
 //Para haiku
-#ifdef HAIKU_OS
+#if defined(HAIKU_OS) || defined(__DragonFly__)
 typedef unsigned int uint;
 
 #else
