From e41ca0a00f88ef8f8d1999417f198db033172f8d Mon Sep 17 00:00:00 2001
From: Emmanuel Vadot <manu@FreeBSD.org>
Date: Thu, 4 Jun 2020 11:05:27 +0200
Subject: [PATCH] xf86Mode: Always include sys/types.h

On FreeBSD when building with GCC this include is needed for sysctl.h
On Clang based build it is included via header polution and I'm sure
that it is also the case on Linux.

Signed-off-by: Emmanuel Vadot <manu@FreeBSD.org>
---
 xf86drmMode.c | 1 +
 1 file changed, 1 insertion(+)

diff --git a/xf86drmMode.c b/xf86drmMode.c
index 5af27c4a..6121fe89 100644
--- xf86drmMode.c
+++ xf86drmMode.c
@@ -41,6 +41,7 @@
 #include <limits.h>
 #include <stdint.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/ioctl.h>
 #if HAVE_SYS_SYSCTL_H
 #include <sys/sysctl.h>
-- 
2.26.2

