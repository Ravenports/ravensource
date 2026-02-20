$NetBSD: patch-src_rrd__list.c,v 1.2 2019/02/11 08:22:45 adam Exp $

Need limits.h for PATH_MAX

--- src/rrd_list.c.orig	2024-07-29 07:08:58 UTC
+++ src/rrd_list.c
@@ -13,6 +13,7 @@
 #endif
 #include <dirent.h>
 #endif
+#include <limits.h>
 #include <sys/types.h>
 
 #include "rrd_tool.h"
