--- tools/configure/configure-tests-mysql.adb.orig	2015-03-17 15:01:56 UTC
+++ tools/configure/configure-tests-mysql.adb
@@ -219,7 +219,7 @@ package body Configure.Tests.MySQL is
              (MySQL_Library_Options,
               +"""-L"
                  & Self.Switches.Libdir
-                 & """, ""-lmysqlclient_r""");
+                 & """, ""-lmysqlclient_r"", ""-Wl,-rpath,@PREFIX@/lib/mysql""");
 
             Self.Report_Status ("yes (command line)");
 
