--- lib/rubygems/platform.rb.orig	2023-09-27 11:09:10 UTC
+++ lib/rubygems/platform.rb
@@ -111,6 +111,7 @@ class Gem::Platform
         @cpu = "x86" if @cpu.nil? && os =~ /32$/
         [os, version]
       when /netbsdelf/ then             [ "netbsdelf", nil ]
+      when /netbsd/ then                [ "netbsd",    $1  ]
       when /openbsd(\d+\.\d+)?/ then    [ "openbsd",   $1  ]
       when /solaris(\d+\.\d+)?/ then    [ "solaris",   $1  ]
       # test
