--- tools/configure/configure-tests-mysql.adb.orig	2021-08-30 10:37:26 UTC
+++ tools/configure/configure-tests-mysql.adb
@@ -223,7 +223,7 @@ package body Configure.Tests.MySQL is
              (MySQL_Library_Options,
               +"""-L"
                  & Self.Switches.Libdir
-                 & """, ""-lmysqlclient_r""");
+                 & """, ""-lmysqlclient_r"", ""-Wl,-rpath,@PREFIX@/lib/mysql""");
 
             Self.Report_Status ("yes (command line)");
 
