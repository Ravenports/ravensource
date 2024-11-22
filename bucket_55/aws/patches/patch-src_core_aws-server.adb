--- src/core/aws-server.adb.orig	2024-09-18 15:17:37 UTC
+++ src/core/aws-server.adb
@@ -970,7 +970,7 @@ package body AWS.Server is
 
          S.Phase := Wait_For_Client;
 
-         Reference := S.Wait_For_Data'Access;
+         Reference := S.Wait_For_Data'Unchecked_Access;
       end Get_Wait_For_Data;
 
       -------------------------------------
