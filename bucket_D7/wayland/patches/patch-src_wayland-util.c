--- src/wayland-util.c.orig	2018-08-24 18:04:36 UTC
+++ src/wayland-util.c
@@ -29,6 +29,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdarg.h>
+#include <pthread.h>
 
 #include "wayland-util.h"
 #include "wayland-private.h"
