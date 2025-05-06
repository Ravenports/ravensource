$NetBSD: patch-sope-core_NGStreams_NGLocalSocketDomain.m,v 1.1 2021/06/14 16:51:39 gdt Exp $

Add support for DragonFly.

--- sope-core/NGStreams/NGLocalSocketDomain.m.orig	2025-04-30 09:04:04 UTC
+++ sope-core/NGStreams/NGLocalSocketDomain.m
@@ -25,7 +25,7 @@
 #include "NGLocalSocketAddress.h"
 #include "NGSocket.h"
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #  include <sys/socket.h>
 #else
