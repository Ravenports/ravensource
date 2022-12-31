--- nokogiri.gemspec.orig	2022-12-31 06:50:00 UTC
+++ nokogiri.gemspec
@@ -27,7 +27,6 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<mini_portile2>.freeze, ["~> 2.8.0"])
-  s.add_runtime_dependency(%q<racc>.freeze, ["~> 1.4"])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.2"])
   s.add_development_dependency(%q<hoe-markdown>.freeze, ["~> 1.4"])
   s.add_development_dependency(%q<minitest>.freeze, ["~> 5.15"])
