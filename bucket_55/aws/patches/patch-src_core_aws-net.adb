--- src/core/aws-net.adb.orig	2021-05-19 05:14:31 UTC
+++ src/core/aws-net.adb
@@ -655,7 +655,7 @@ package body AWS.Net is
 
          --  to be shure that it is S1 and S2 connected together
 
-         exit when Peer_Addr (STC (S2)) = Local_Host
+         exit when Peer_Addr (STC (S2)) = Get_Addr (STC (S1))
            and then Peer_Port (STC (S2)) = Get_Port (STC (S1))
            and then Peer_Port (STC (S1)) = Get_Port (STC (S2));
 
