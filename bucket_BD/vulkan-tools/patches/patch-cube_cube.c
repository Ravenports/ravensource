--- cube/cube.c.orig	2026-08-28 03:05:46 UTC
+++ cube/cube.c
@@ -5108,7 +5108,7 @@ void android_main(struct android_app *ap
         }
     }
 }
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || defined(__DragonFly__)
 int main(int argc, char **argv) {
     struct demo demo;
 
