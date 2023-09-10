--- src/test-main.adb.orig	2023-07-19 08:54:01 UTC
+++ src/test-main.adb
@@ -31,6 +31,8 @@ with Test.Common;
 
 procedure Test.Main is
 
+   pragma Linker_Options ("-lgnarl");
+   pragma Linker_Options ("-lpthread");
    --  Main procedure for gnattest
 
    procedure Callback (Phase : Parse_Phase; Swit : Dynamically_Typed_Switch);
