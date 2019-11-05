$NetBSD: patch-src_loader_loader.c,v 1.5 2019/08/29 14:12:57 nia Exp $

Include limits.h for PATH_MAX.

--- src/loader/loader.c.orig	2019-10-24 16:13:04 UTC
+++ src/loader/loader.c
@@ -36,6 +36,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <limits.h>
 #include <sys/param.h>
 #ifdef MAJOR_IN_MKDEV
 #include <sys/mkdev.h>
