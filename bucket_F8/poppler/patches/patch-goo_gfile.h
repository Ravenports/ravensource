--- goo/gfile.h.orig	2018-03-18 18:23:49 UTC
+++ goo/gfile.h
@@ -37,6 +37,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
+#include <time.h>
 extern "C" {
 #if defined(_WIN32)
 #  include <sys/stat.h>
