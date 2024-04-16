--- lib/facter/framework/detector/os_detector.rb.orig	2024-04-15 23:56:19 UTC
+++ lib/facter/framework/detector/os_detector.rb
@@ -26,6 +26,8 @@ class OsDetector
                    detect_distro
                  when /freebsd/
                    :freebsd
+                 when /dragonfly/
+                   :bsd
                  when /openbsd/i
                    :openbsd
                  when /bsd/
