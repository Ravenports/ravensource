--- util/geosop/cxxopts.hpp.orig	2025-10-27 15:13:40 UTC
+++ util/geosop/cxxopts.hpp
@@ -677,7 +677,7 @@ namespace cxxopts
       integer_parser(text, value);
     }
 
-    #ifndef __illumos__
+    #ifndef __sun
     inline
     void
     parse_value(const std::string& text, int8_t& value)
