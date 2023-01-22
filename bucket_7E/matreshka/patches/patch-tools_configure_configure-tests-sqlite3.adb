--- tools/configure/configure-tests-sqlite3.adb.orig	2021-08-30 10:37:26 UTC
+++ tools/configure/configure-tests-sqlite3.adb
@@ -87,7 +87,7 @@ package body Configure.Tests.SQLite3 is
              (SQLite3_Library_Options,
               +"""-L"
                  & Self.Switches.Libdir
-                 & """, ""-lsqlite3""");
+                 & """, ""-Lsqlite3"", ""-Wl,-rpath,@PREFIX@/lib""");
 
             Self.Report_Status ("yes (command line)");
 
@@ -126,6 +126,7 @@ package body Configure.Tests.SQLite3 is
                            Append (Opts, '"');
                         end loop;
 
+                        Append (Opts, ", ""-Wl,-rpath,@PREFIX@/lib""");
                         Substitutions.Insert (SQLite3_Library_Options, Opts);
 
                         Self.Report_Status (+Opts);
