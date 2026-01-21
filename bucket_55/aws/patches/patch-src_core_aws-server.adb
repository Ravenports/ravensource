--- src/core/aws-server.adb.orig	2025-09-18 19:54:11 UTC
+++ src/core/aws-server.adb
@@ -975,7 +975,7 @@ package body AWS.Server is
 
          S.Phase := Wait_For_Client;
 
-         Reference := S.Wait_For_Data'Access;
+         Reference := S.Wait_For_Data'Unchecked_Access;
       end Get_Wait_For_Data;
 
       -------------------------------------
