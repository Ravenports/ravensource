--- lib/src/util/config/posix/config.cc.orig	2020-08-03 13:10:15 UTC
+++ lib/src/util/config/posix/config.cc
@@ -7,6 +7,6 @@ namespace facter { namespace util { name
     }
 
     std::string default_config_location() {
-        return "/etc/puppetlabs/facter/facter.conf";
+        return "%%PREFIX%%/etc/facter/facter.conf";
     }
 }}}  // namespace facter::util::config
