--- nokogiri.gemspec.orig	2022-10-11 23:51:26 UTC
+++ nokogiri.gemspec
@@ -30,7 +30,6 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<mini_portile2>.freeze, ["~> 2.8.0"])
-    s.add_runtime_dependency(%q<racc>.freeze, ["~> 1.4"])
     s.add_development_dependency(%q<bundler>.freeze, ["~> 2.2"])
     s.add_development_dependency(%q<hoe-markdown>.freeze, ["~> 1.4"])
     s.add_development_dependency(%q<minitest>.freeze, ["~> 5.15"])
@@ -49,7 +48,6 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<simplecov>.freeze, ["~> 0.21"])
   else
     s.add_dependency(%q<mini_portile2>.freeze, ["~> 2.8.0"])
-    s.add_dependency(%q<racc>.freeze, ["~> 1.4"])
     s.add_dependency(%q<bundler>.freeze, ["~> 2.2"])
     s.add_dependency(%q<hoe-markdown>.freeze, ["~> 1.4"])
     s.add_dependency(%q<minitest>.freeze, ["~> 5.15"])
