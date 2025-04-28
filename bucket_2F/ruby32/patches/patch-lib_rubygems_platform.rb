$NetBSD: patch-lib_rubygems_platform.rb,v 1.1 2023/01/21 13:51:23 taca Exp $

* Don't replace "i486" to "x86".
* Allow simple "netbsd" as Gem::Platform.

--- lib/rubygems/platform.rb.orig	2025-03-26 04:18:02 UTC
+++ lib/rubygems/platform.rb
@@ -77,12 +77,7 @@ class Gem::Platform
         arch.last << "-#{extra}"
       end
 
-      cpu = arch.shift
-
-      @cpu = case cpu
-      when /i\d86/ then "x86"
-      else cpu
-      end
+      @cpu = arch.shift
 
       if arch.length == 2 && arch.last =~ /^\d+(\.\d+)?$/ # for command-line
         @os, @version = arch
@@ -111,6 +106,7 @@ class Gem::Platform
         @cpu = "x86" if @cpu.nil? && os =~ /32$/
         [os, version]
       when /netbsdelf/ then             [ "netbsdelf", nil ]
+      when /netbsd/ then                [ "netbsd",    nil ]
       when /openbsd(\d+\.\d+)?/ then    [ "openbsd",   $1  ]
       when /solaris(\d+\.\d+)?/ then    [ "solaris",   $1  ]
       # test
