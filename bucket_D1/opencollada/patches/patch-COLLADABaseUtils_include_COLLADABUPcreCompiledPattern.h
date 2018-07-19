From b7780cd366dd687ff5e517ad95885408db96c7b5 Mon Sep 17 00:00:00 2001
From: Dennis Schridde <devurandom@gmx.net>
Date: Thu, 12 Jul 2018 06:52:36 +0200
Subject: [PATCH] COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h:
 Include pcre.h

This fixes a compilation error with libpcre-8.42:
```
error: conflicting declaration 'typedef struct real_pcre8_or_16 pcre'
```

Closes: #547
Closes: #570
---
 COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h | 3 +--
 1 file changed, 1 insertion(+), 2 deletions(-)

--- COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h
+++ COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h
@@ -13,8 +13,7 @@
 
 #include "COLLADABUPrerequisites.h"
 
-struct real_pcre;
-typedef struct real_pcre pcre;
+#include <pcre.h>
 
 
 namespace COLLADABU
