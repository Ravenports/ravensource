--- config/config_ruby.rb.orig	2021-03-16 00:04:01 UTC
+++ config/config_ruby.rb
@@ -5,11 +5,14 @@ CONFIG = RbConfig::MAKEFILE_CONFIG
 
 case ARGV[0]
 when "archdir"
-    puts RbConfig::expand(CONFIG["archdir"])
+    puts RbConfig::expand(CONFIG["rubyhdrdir"])
+when "inc"
+    print RbConfig::expand(CONFIG["rubyhdrdir"]) + '/'
+    puts RbConfig::expand(CONFIG["sitearch"])
 when "lib"
     puts RbConfig::expand(CONFIG["libdir"])
 when "vendorarchdir"
-    puts RbConfig::expand(CONFIG["vendorarchdir"])
+    puts RbConfig::expand(CONFIG["sitearchdir"])
 when "sitearchdir"
     puts RbConfig::expand(CONFIG["sitearchdir"])
 when "sitelib"
