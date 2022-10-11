--- ronn-ng.gemspec.orig	2022-10-11 23:13:51 UTC
+++ ronn-ng.gemspec
@@ -27,8 +27,8 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<kramdown>.freeze, ["~> 2.1"])
-    s.add_runtime_dependency(%q<mustache>.freeze, ["~> 0.7", ">= 0.7.0"])
-    s.add_runtime_dependency(%q<nokogiri>.freeze, ["~> 1.9", ">= 1.9.0"])
+    s.add_runtime_dependency(%q<mustache>.freeze, [">= 0.7.0"])
+    s.add_runtime_dependency(%q<nokogiri>.freeze, [">= 1.9.0"])
     s.add_development_dependency(%q<rack>.freeze, ["~> 2.0", ">= 2.0.6"])
     s.add_development_dependency(%q<rake>.freeze, ["~> 12.3", ">= 12.3.0"])
     s.add_development_dependency(%q<rubocop>.freeze, ["~> 0.60", ">= 0.57.1"])
@@ -36,8 +36,8 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<test-unit>.freeze, ["~> 3.2", ">= 3.2.7"])
   else
     s.add_dependency(%q<kramdown>.freeze, ["~> 2.1"])
-    s.add_dependency(%q<mustache>.freeze, ["~> 0.7", ">= 0.7.0"])
-    s.add_dependency(%q<nokogiri>.freeze, ["~> 1.9", ">= 1.9.0"])
+    s.add_dependency(%q<mustache>.freeze, [">= 0.7.0"])
+    s.add_dependency(%q<nokogiri>.freeze, [">= 1.9.0"])
     s.add_dependency(%q<rack>.freeze, ["~> 2.0", ">= 2.0.6"])
     s.add_dependency(%q<rake>.freeze, ["~> 12.3", ">= 12.3.0"])
     s.add_dependency(%q<rubocop>.freeze, ["~> 0.60", ">= 0.57.1"])
