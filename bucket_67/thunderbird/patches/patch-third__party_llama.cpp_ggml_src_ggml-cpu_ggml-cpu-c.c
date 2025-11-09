--- third_party/llama.cpp/ggml/src/ggml-cpu/ggml-cpu-c.c.orig	2025-10-16 03:20:41 UTC
+++ third_party/llama.cpp/ggml/src/ggml-cpu/ggml-cpu-c.c
@@ -17,7 +17,7 @@
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #include <malloc.h> // using malloc.h with MSC/MINGW
-#elif !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
+#elif !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 #include <alloca.h>
 #endif
 
