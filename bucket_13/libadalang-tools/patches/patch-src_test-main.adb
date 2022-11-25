--- src/test-main.adb.orig	2022-09-22 17:08:03 UTC
+++ src/test-main.adb
@@ -30,6 +30,8 @@ with Test.Common;
 
 procedure Test.Main is
 
+   pragma Linker_Options ("-lgnarl");
+   pragma Linker_Options ("-lpthread");
    --  Main procedure for gnattest
 
    procedure Callback (Phase : Parse_Phase; Swit : Dynamically_Typed_Switch);
