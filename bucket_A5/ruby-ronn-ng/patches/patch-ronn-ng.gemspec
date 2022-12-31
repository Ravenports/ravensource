--- ronn-ng.gemspec.orig	2022-12-31 16:09:11 UTC
+++ ronn-ng.gemspec
@@ -24,8 +24,8 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<kramdown>.freeze, ["~> 2.1"])
-  s.add_runtime_dependency(%q<mustache>.freeze, ["~> 0.7", ">= 0.7.0"])
-  s.add_runtime_dependency(%q<nokogiri>.freeze, ["~> 1.9", ">= 1.9.0"])
+  s.add_runtime_dependency(%q<mustache>.freeze, [">= 0.7.0"])
+  s.add_runtime_dependency(%q<nokogiri>.freeze, [">= 1.9.0"])
   s.add_development_dependency(%q<rack>.freeze, ["~> 2.0", ">= 2.0.6"])
   s.add_development_dependency(%q<rake>.freeze, ["~> 12.3", ">= 12.3.0"])
   s.add_development_dependency(%q<rubocop>.freeze, ["~> 0.60", ">= 0.57.1"])
