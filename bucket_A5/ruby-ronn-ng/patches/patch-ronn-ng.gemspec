--- ronn-ng.gemspec.orig	2024-01-17 17:36:44.807848000 +0000
+++ ronn-ng.gemspec	2024-01-17 17:39:12.848024000 +0000
@@ -27,7 +27,7 @@
   s.add_runtime_dependency(%q<kramdown>.freeze, ["~> 2".freeze, ">= 2.1".freeze])
   s.add_runtime_dependency(%q<kramdown-parser-gfm>.freeze, ["~> 1".freeze, ">= 1.0.1".freeze])
   s.add_runtime_dependency(%q<mustache>.freeze, ["~> 1".freeze])
-  s.add_runtime_dependency(%q<nokogiri>.freeze, ["~> 1".freeze, ">= 1.14.3".freeze])
+  s.add_runtime_dependency(%q<nokogiri>.freeze, [">= 1.14.3".freeze])
   s.add_development_dependency(%q<rack>.freeze, ["~> 2".freeze, ">= 2.2.3".freeze])
   s.add_development_dependency(%q<rake>.freeze, ["~> 13".freeze, ">= 13.0.3".freeze])
   s.add_development_dependency(%q<rubocop>.freeze, ["~> 1".freeze, ">= 1.25.1".freeze])
