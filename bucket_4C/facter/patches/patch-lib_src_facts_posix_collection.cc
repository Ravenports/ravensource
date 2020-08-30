--- lib/src/facts/posix/collection.cc.orig	2020-08-03 13:10:15 UTC
+++ lib/src/facts/posix/collection.cc
@@ -22,9 +22,8 @@ namespace facter { namespace facts {
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
