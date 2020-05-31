--- lib/src/tokenizer.cc.orig	2019-12-12 09:56:44 UTC
+++ lib/src/tokenizer.cc
@@ -5,7 +5,7 @@
 #include <internal/values/config_double.hpp>
 #include <internal/values/config_long.hpp>
 #include <internal/values/config_string.hpp>
-#include <boost/nowide/fstream.hpp>
+#include <boost/nowide/convert.hpp>
 #include <boost/lexical_cast.hpp>
 #include <leatherman/locale/locale.hpp>
 
