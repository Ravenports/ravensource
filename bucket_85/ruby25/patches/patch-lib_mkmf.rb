--- lib/mkmf.rb.orig	2017-12-11 02:30:42 UTC
+++ lib/mkmf.rb
@@ -234,7 +234,7 @@ module MakeMakefile
   end
   $extmk ||= false
   if not $extmk and File.exist?(($hdrdir = RbConfig::CONFIG["rubyhdrdir"]) + "/ruby/ruby.h")
-    $topdir = $hdrdir
+    $topdir = $hdrdir + "/" + "#{CONFIG['arch']}/ruby/"
     $top_srcdir = $hdrdir
     $arch_hdrdir = RbConfig::CONFIG["rubyarchhdrdir"]
   elsif File.exist?(($hdrdir = ($top_srcdir ||= topdir) + "/include")  + "/ruby.h")
