From 73b10ad26d51309852e87e74cb4e6d27f2faf33b Mon Sep 17 00:00:00 2001
From: John Safranek <john@wolfssl.com>
Date: Thu, 30 Apr 2026 14:04:30 -0700
Subject: [PATCH] Drop redundant mlkem.h include

---
 src/internal.c | 3 +--
 1 file changed, 1 insertion(+), 2 deletions(-)

--- src/internal.c.orig
+++ src/internal.c
@@ -57,8 +57,7 @@
 #endif
 
 #ifdef WOLFSSL_HAVE_MLKEM
-#include <wolfssl/wolfcrypt/mlkem.h>
-#include <wolfssl/wolfcrypt/wc_mlkem.h>
+    #include <wolfssl/wolfcrypt/wc_mlkem.h>
 #endif
 
 #ifdef NO_INLINE
