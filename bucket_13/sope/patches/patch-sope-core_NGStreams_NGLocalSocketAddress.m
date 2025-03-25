$NetBSD: patch-sope-core_NGStreams_NGLocalSocketAddress.m,v 1.1 2021/06/14 16:51:39 gdt Exp $

Add support for DragonFly.

--- sope-core/NGStreams/NGLocalSocketAddress.m.orig	2025-03-24 09:41:38 UTC
+++ sope-core/NGStreams/NGLocalSocketAddress.m
@@ -28,7 +28,7 @@
 
 #include "config.h"
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #else
 #  include <sys/un.h>
