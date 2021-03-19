--- libgnucash/engine/kvp-value.hpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/engine/kvp-value.hpp
@@ -24,10 +24,10 @@
 #ifndef GNC_KVP_VALUE_TYPE
 #define GNC_KVP_VALUE_TYPE
 
+#include "qof.h"
 extern "C"
 {
 #include <config.h>
-#include "qof.h"
 }
 #include <boost/version.hpp>
 #if BOOST_VERSION == 105600
