--- libgnucash/engine/qofobject.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/engine/qofobject.cpp
@@ -23,12 +23,9 @@
  * Copyright (C) 2001 Derek Atkins
  * Author: Derek Atkins <warlord@MIT.EDU>
  */
-extern "C"
-{
+
 #include <config.h>
 #include <glib.h>
-}
-
 #include "qof.h"
 #include "qofobject-p.h"
 
