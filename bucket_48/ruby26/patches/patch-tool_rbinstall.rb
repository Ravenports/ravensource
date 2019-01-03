--- tool/rbinstall.rb.orig	2018-12-20 04:03:07 UTC
+++ tool/rbinstall.rb
@@ -722,22 +722,6 @@ end
 
 # :startdoc:
 
-install?(:ext, :comm, :gem, :'default-gems', :'default-gems-comm') do
-  install_default_gem('lib', srcdir)
-end
-install?(:ext, :arch, :gem, :'default-gems', :'default-gems-arch') do
-  install_default_gem('ext', srcdir) do |path|
-    # assume that gemspec and extconf.rb are placed in the same directory
-    success = false
-    begin
-      IO.foreach(File.dirname(path[(srcdir.size+1)..-1]) + "/Makefile") do |l|
-        break success = true if /^TARGET\s*=/ =~ l
-      end
-    rescue Errno::ENOENT
-    end
-    success
-  end
-end
 
 def load_gemspec(file)
   file = File.realpath(file)
