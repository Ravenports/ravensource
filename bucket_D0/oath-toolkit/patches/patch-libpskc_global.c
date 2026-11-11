From dd5e9fa69ddad60b136c9df970f0e86c366478a7 Mon Sep 17 00:00:00 2001
From: Paul Zander <negril.nx+gentoo@gmail.com>
Date: Sun, 1 Nov 2026 15:58:15 +0100
Subject: [PATCH] libpskc: fix implicit-function-declaration with newer xmlsec

Bug: https://bugs.gentoo.org/985360
---
 libpskc/global.c | 1 +
 1 file changed, 1 insertion(+)

--- libpskc/global.c.orig
+++ libpskc/global.c
@@ -30,6 +30,7 @@
 #ifdef USE_XMLSEC
 # include <xmlsec/xmlsec.h>
 # include <xmlsec/crypto.h>
+# include <xmlsec/dl.h>
 #endif
 
 static int _pskc_init = 0;
