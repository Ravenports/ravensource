--- lib/src/util/config/posix/config.cc.orig	2018-12-03 19:36:37 UTC
+++ lib/src/util/config/posix/config.cc
@@ -7,6 +7,6 @@ namespace facter { namespace util { name
     }
 
     std::string default_config_location() {
-        return "/etc/puppetlabs/facter/facter.conf";
+        return "%%PREFIX%%/etc/facter/facter.conf";
     }
 }}}  // namespace facter::util::config
