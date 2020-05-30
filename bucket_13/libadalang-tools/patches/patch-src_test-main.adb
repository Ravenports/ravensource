--- src/test-main.adb.orig	2020-02-28 06:08:56 UTC
+++ src/test-main.adb
@@ -6,6 +6,8 @@ with Test.Command_Lines;
 
 procedure Test.Main is
 
+   pragma Linker_Options ("-lgnarl");
+   pragma Linker_Options ("-lpthread");
    --  Main procedure for gnattest
 
    procedure Callback (Phase : Parse_Phase; Swit : Dynamically_Typed_Switch);
