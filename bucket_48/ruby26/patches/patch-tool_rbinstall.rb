--- tool/rbinstall.rb.orig	2019-01-24 01:00:07 UTC
+++ tool/rbinstall.rb
@@ -785,13 +785,6 @@ end
 
 # :startdoc:
 
-install?(:ext, :comm, :gem, :'default-gems', :'default-gems-comm') do
-  install_default_gem('lib', srcdir)
-end
-install?(:ext, :arch, :gem, :'default-gems', :'default-gems-arch') do
-  install_default_gem('ext', srcdir)
-end
-
 def load_gemspec(file)
   file = File.realpath(file)
   code = File.read(file, encoding: "utf-8:-")
