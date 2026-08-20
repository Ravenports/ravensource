--- lzma/C/CpuArch.c.orig	2026-08-05 14:31:46 UTC
+++ lzma/C/CpuArch.c
@@ -877,7 +877,7 @@ BoolInt CPU_IsSupported_AES (void) { ret
 
 #ifdef USE_HWCAP
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 static unsigned long MY_getauxval(int aux)
 {
   unsigned long val;
