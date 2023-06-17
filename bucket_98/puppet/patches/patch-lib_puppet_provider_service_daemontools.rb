Daemontools program locations

--- lib/puppet/provider/service/daemontools.rb.orig	2023-06-06 21:43:12 UTC
+++ lib/puppet/provider/service/daemontools.rb
@@ -40,7 +40,7 @@ Puppet::Type.type(:service).provide :dae
 
   EOT
 
-  commands :svc  => "/usr/bin/svc", :svstat => "/usr/bin/svstat"
+  commands :svc  => "%%PREFIX%%/bin/svc", :svstat => "%%PREFIX%%/bin/svstat"
 
   class << self
     attr_writer :defpath
@@ -87,7 +87,7 @@ Puppet::Type.type(:service).provide :dae
   # find the service dir on this node
   def servicedir
     unless @servicedir
-      ["/service", "/etc/service","/var/lib/svscan"].each do |path|
+      ["/var/service", "/etc/service","/var/lib/svscan"].each do |path|
         if Puppet::FileSystem.exist?(path)
           @servicedir = path
           break
