--- libgnucash/engine/qofsession.cpp.orig	2020-09-27 18:52:46 UTC
+++ libgnucash/engine/qofsession.cpp
@@ -32,8 +32,6 @@
  @author Copyright (c) 2016 Aaron Laws
    */
 
-extern "C"
-{
 
 #include <config.h>
 
@@ -53,7 +51,6 @@ extern "C"
 #include "qofobject-p.h"
 
 static QofLogModule log_module = QOF_MOD_SESSION;
-} //extern 'C'
 
 #include "qofbook-p.h"
 #include "qof-backend.hpp"
