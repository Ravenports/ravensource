--- lib/rubygems/platform.rb.orig	2025-07-21 16:04:55 UTC
+++ lib/rubygems/platform.rb
@@ -122,6 +122,7 @@ class Gem::Platform
                         @cpu = "x86" if @cpu.nil? && os.end_with?("32")
                         [os, version]
                       when /netbsdelf/ then                  ["netbsdelf", nil]
+                      when /netbsd/ then                     ["netbsd",    $1]
                       when /openbsd-?(\d+\.\d+)?/ then       ["openbsd",   $1]
                       when /solaris-?(\d+\.\d+)?/ then       ["solaris",   $1]
                       when /wasi/ then                       ["wasi",      nil]
