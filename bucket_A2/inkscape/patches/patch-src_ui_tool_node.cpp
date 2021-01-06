--- src/ui/tool/node.cpp.orig	2020-09-07 09:02:10 UTC
+++ src/ui/tool/node.cpp
@@ -7,6 +7,7 @@
  * Released under GNU GPL v2+, read the file 'COPYING' for more information.
  */
 
+#include <atomic>
 #include <iostream>
 #include <stdexcept>
 #include <boost/utility.hpp>
