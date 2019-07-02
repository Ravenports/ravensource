--- src/core/aws-net.adb.orig	2019-05-13 04:05:48 UTC
+++ src/core/aws-net.adb
@@ -641,7 +641,7 @@ package body AWS.Net is
 
          --  to be shure that it is S1 and S2 connected together
 
-         exit when Peer_Addr (STC (S2)) = Local_Host
+         exit when Peer_Addr (STC (S2)) = Get_Addr (STC (S1))
            and then Peer_Port (STC (S2)) = Get_Port (STC (S1))
            and then Peer_Port (STC (S1)) = Get_Port (STC (S2));
 
