--- ext/nokogiri/extconf.rb.orig	2021-09-04 16:46:36 UTC
+++ ext/nokogiri/extconf.rb
@@ -14,7 +14,7 @@ RECOMMENDED_LIBXML_VERSION = "2.9.3"
 
 # The gem version constraint in the Rakefile is not respected at install time.
 # Keep this version in sync with the one in the Rakefile !
-REQUIRED_MINI_PORTILE_VERSION = "~> 2.6.1"
+REQUIRED_MINI_PORTILE_VERSION = "~> 2.7"
 REQUIRED_PKG_CONFIG_VERSION = "~> 1.1"
 
 # Keep track of what versions of what libraries we build against
