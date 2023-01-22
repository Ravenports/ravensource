--- tools/configure/configure-tests-postgresql.adb.orig	2021-08-30 10:37:26 UTC
+++ tools/configure/configure-tests-postgresql.adb
@@ -187,7 +187,7 @@ package body Configure.Tests.PostgreSQL
              (PostgreSQL_Library_Options,
               +"""-L"
                  & Self.Switches.Libdir
-                 & """, ""-lpq""");
+                 & """, ""-lpq"", ""-Wl,-rpath,@PREFIX@/lib""");
 
             Self.Report_Status ("yes (command line)");
 
@@ -197,7 +197,7 @@ package body Configure.Tests.PostgreSQL
          elsif Has_Pg_Config then
             Self.Report_Status ("yes (pg_config)");
             Substitutions.Insert
-             (PostgreSQL_Library_Options, +"""-L" & Pg_Libdir & """, ""-lpq""");
+             (PostgreSQL_Library_Options, +"""-L" & Pg_Libdir & """, ""-lpq"", ""-Wl,-rpath,@PREFIX@/lib""");
 
          else
             Self.Report_Status ("no (pg_config not found)");
