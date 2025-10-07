From 4fe040290da2822c70d3b60d30a2c1256264735d Mon Sep 17 00:00:00 2001
From: Niels Dossche <7771979+nielsdos@users.noreply.github.com>
Date: Wed, 1 Oct 2025 11:01:31 +0200
Subject: [PATCH] Fix GH-20022: docker-php-ext-install DOM failed

---
 ext/dom/lexbor/lexbor/selectors-adapted/selectors.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

--- lexbor/lexbor/selectors-adapted/selectors.c.orig
+++ lexbor/lexbor/selectors-adapted/selectors.c
@@ -13,7 +13,7 @@
 #include <Zend/zend_API.h>
 #include <php.h>
 
-#include "ext/dom/lexbor/lexbor/selectors-adapted/selectors.h"
+#include "lexbor/lexbor/selectors-adapted/selectors.h"
 #include "../../../namespace_compat.h"
 #include "../../../domexception.h"
 #include "../../../php_dom.h"
