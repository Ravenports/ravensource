--- third_party/llama.cpp/ggml/src/ggml-c.c.orig	2025-12-05 17:43:19 UTC
+++ third_party/llama.cpp/ggml/src/ggml-c.c
@@ -16,7 +16,7 @@
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #include <malloc.h> // using malloc.h with MSC/MINGW
-#elif !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
+#elif !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 #include <alloca.h>
 #endif
 
