--- lib/src/tokenizer.cc.orig	2018-10-11 16:55:40 UTC
+++ lib/src/tokenizer.cc
@@ -5,7 +5,7 @@
 #include <internal/values/config_double.hpp>
 #include <internal/values/config_long.hpp>
 #include <internal/values/config_string.hpp>
-#include <boost/nowide/fstream.hpp>
+#include <boost/nowide/convert.hpp>
 #include <boost/lexical_cast.hpp>
 #include <leatherman/locale/locale.hpp>
 
