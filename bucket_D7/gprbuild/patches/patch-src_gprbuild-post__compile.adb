--- src/gprbuild-post_compile.adb.orig	2016-12-23 15:59:49 UTC
+++ src/gprbuild-post_compile.adb
@@ -1794,11 +1794,7 @@ package body Gprbuild.Post_Compile is
                      end if;
 
                      if not OK then
-                        Error_Msg
-                          (Msg           => "unknown object file " &
-                                             Name_Buffer (1 .. Name_Len),
-                           Flag_Location => Library_Options.Location);
-                        Success := False;
+                        null;
                      end if;
 
                      List := Elem.Next;
