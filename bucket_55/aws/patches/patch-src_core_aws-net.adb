--- src/core/aws-net.adb.orig	2022-09-20 17:13:06 UTC
+++ src/core/aws-net.adb
@@ -661,7 +661,7 @@ package body AWS.Net is
 
          --  to be shure that it is S1 and S2 connected together
 
-         exit when Peer_Addr (STC (S2)) = Local_Host
+         exit when Peer_Addr (STC (S2)) = Get_Addr (STC (S1))
            and then Peer_Port (STC (S2)) = Get_Port (STC (S1))
            and then Peer_Port (STC (S1)) = Get_Port (STC (S2));
 
