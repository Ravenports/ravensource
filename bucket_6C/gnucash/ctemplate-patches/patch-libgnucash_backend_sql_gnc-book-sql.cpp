--- libgnucash/backend/sql/gnc-book-sql.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/backend/sql/gnc-book-sql.cpp
@@ -25,8 +25,6 @@
  * This file implements the top-level QofBackend API for saving/
  * restoring data to/from an SQL db
  */
-extern "C"
-{
 #include <config.h>
 
 #include <glib.h>
@@ -40,7 +38,6 @@ extern "C"
 #if defined( S_SPLINT_S )
 #include "splint-defs.h"
 #endif
-}
 
 #include "gnc-sql-connection.hpp"
 #include "gnc-sql-backend.hpp"
