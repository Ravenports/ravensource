--- lib/src/facts/posix/collection.cc.orig	2018-09-14 15:27:42 UTC
+++ lib/src/facts/posix/collection.cc
@@ -26,9 +26,8 @@ namespace facter { namespace facts {
                 directories.emplace_back(home + "/.facter/facts.d");
             }
         } else {
-            directories.emplace_back("/opt/puppetlabs/facter/facts.d");
-            directories.emplace_back("/etc/facter/facts.d");
-            directories.emplace_back("/etc/puppetlabs/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/facter/facts.d");
+            directories.emplace_back("%%PREFIX%%/etc/puppetlabs/facter/facts.d");
         }
         return directories;
     }
