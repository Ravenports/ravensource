--- lib/facter/framework/detector/os_detector.rb.orig	2020-12-09 02:51:15 UTC
+++ lib/facter/framework/detector/os_detector.rb
@@ -26,6 +26,8 @@ class OsDetector
                    detect_distro
                  when /freebsd/
                    :freebsd
+                 when /dragonfly/
+                   :bsd		
                  when /bsd/
                    :bsd
                  when /solaris/
