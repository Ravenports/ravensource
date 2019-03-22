--- src/wayland-util.c.orig	2019-03-21 00:55:25 UTC
+++ src/wayland-util.c
@@ -29,6 +29,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdarg.h>
+#include <pthread.h>
 
 #include "wayland-util.h"
 #include "wayland-private.h"
