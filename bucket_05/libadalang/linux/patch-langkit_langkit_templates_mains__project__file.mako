--- langkit/langkit/templates/mains_project_file.mako.orig	2018-04-25 09:45:20 UTC
+++ langkit/langkit/templates/mains_project_file.mako
@@ -40,4 +40,8 @@ project Mains is
       for Switches ("ada") use ("-E");
    end Binder;
 
+   package Linker is
+      for Switches ("ada") use ("-lgnarl", "-Wl,-rpath,@PREFIX@/lib");
+   end Linker;
+
 end Mains;
