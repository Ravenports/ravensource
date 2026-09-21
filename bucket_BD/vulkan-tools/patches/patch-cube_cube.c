--- cube/cube.c.orig	2026-09-04 03:25:51 UTC
+++ cube/cube.c
@@ -5108,7 +5108,7 @@ void android_main(struct android_app *ap
         }
     }
 }
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || defined(__DragonFly__) || defined(__NetBSD__)
 int main(int argc, char **argv) {
     struct demo demo;
 
