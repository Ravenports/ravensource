--- lib/mkmf.rb.orig	2025-02-14 21:25:54 UTC
+++ lib/mkmf.rb
@@ -242,7 +242,7 @@ module MakeMakefile
   end
   $extmk ||= false
   if not $extmk and File.exist?(($hdrdir = RbConfig::CONFIG["rubyhdrdir"]) + "/ruby/ruby.h")
-    $topdir = $hdrdir
+    $topdir = $hdrdir + "/" + "#{CONFIG['arch']}/ruby/"
     $top_srcdir = $hdrdir
     $arch_hdrdir = RbConfig::CONFIG["rubyarchhdrdir"]
   elsif File.exist?(($hdrdir = ($top_srcdir ||= topdir) + "/include")  + "/ruby.h")
