--- nokogiri.gemspec.orig	2021-09-04 16:41:58 UTC
+++ nokogiri.gemspec
@@ -30,7 +30,7 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<racc>.freeze, ["~> 1.4"])
-    s.add_runtime_dependency(%q<mini_portile2>.freeze, ["~> 2.6.1"])
+    s.add_runtime_dependency(%q<mini_portile2>.freeze, ["~> 2.7"])
     s.add_development_dependency(%q<bundler>.freeze, ["~> 2.2"])
     s.add_development_dependency(%q<hoe-markdown>.freeze, ["~> 1.4"])
     s.add_development_dependency(%q<minitest>.freeze, ["~> 5.8"])
@@ -44,7 +44,7 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<yard>.freeze, ["~> 0.9"])
   else
     s.add_dependency(%q<racc>.freeze, ["~> 1.4"])
-    s.add_dependency(%q<mini_portile2>.freeze, ["~> 2.6.1"])
+    s.add_dependency(%q<mini_portile2>.freeze, ["~> 2.7"])
     s.add_dependency(%q<bundler>.freeze, ["~> 2.2"])
     s.add_dependency(%q<hoe-markdown>.freeze, ["~> 1.4"])
     s.add_dependency(%q<minitest>.freeze, ["~> 5.8"])
