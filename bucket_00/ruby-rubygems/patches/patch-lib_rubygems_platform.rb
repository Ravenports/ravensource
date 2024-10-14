--- lib/rubygems/platform.rb.orig	2024-10-03 18:08:40 UTC
+++ lib/rubygems/platform.rb
@@ -132,6 +132,7 @@ class Gem::Platform
                         @cpu = "x86" if @cpu.nil? && os =~ /32$/
                         [os, version]
                       when /netbsdelf/ then             ["netbsdelf", nil]
+                      when /netbsd/ then                ["netbsd",    $1]
                       when /openbsd(\d+\.\d+)?/ then    ["openbsd",   $1]
                       when /solaris(\d+\.\d+)?/ then    ["solaris",   $1]
                       when /wasi/ then                  ["wasi",      nil]
