--- config/src/aws-net-std__ipv4.adb.orig	2021-05-19 05:14:30 UTC
+++ config/src/aws-net-std__ipv4.adb
@@ -65,10 +65,6 @@ package body AWS.Net.Std is
    --  Set the socket to the non-blocking mode.
    --  AWS is not using blocking sockets internally.
 
-   To_GNAT : constant array (Family_Type) of Sockets.Family_Type :=
-               (Family_Inet   => Sockets.Family_Inet,
-                Family_Inet6  => Sockets.Family_Inet6,
-                Family_Unspec => Sockets.Family_Inet);
 
    -------------------
    -- Accept_Socket --
@@ -141,9 +137,16 @@ package body AWS.Net.Std is
             Option => (Sockets.Reuse_Address, Enabled => True));
       end if;
 
-      Sockets.Bind_Socket
-        (Socket.S.FD,
-         (To_GNAT (Family), Inet_Addr, Sockets.Port_Type (Port)));
+      case Family is
+         when Family_Inet | Family_Unspec =>
+            Sockets.Bind_Socket
+              (Socket.S.FD,
+               (Sockets.Family_Inet, Inet_Addr, Sockets.Port_Type (Port)));
+         when Family_Inet6 =>
+            Sockets.Bind_Socket
+              (Socket.S.FD,
+               (Sockets.Family_Inet6, Inet_Addr, Sockets.Port_Type (Port)));
+      end case;
 
    exception
       when E : Sockets.Socket_Error | Sockets.Host_Error =>
@@ -210,9 +213,16 @@ package body AWS.Net.Std is
 
       Socket.S := new Socket_Hidden;
 
-      Sock_Addr := (To_GNAT (Family),
-                    Get_Inet_Addr (Host, Passive => False),
-                    Sockets.Port_Type (Port));
+      case Family is
+         when Family_Inet | Family_Unspec =>
+            Sock_Addr := (Sockets.Family_Inet,
+                          Get_Inet_Addr (Host, Passive => False),
+                          Sockets.Port_Type (Port));
+         when Family_Inet6 =>
+            Sock_Addr := (Sockets.Family_Inet6,
+                          Get_Inet_Addr (Host, Passive => False),
+                          Sockets.Port_Type (Port));
+      end case;
 
       Sockets.Create_Socket (Socket.S.FD);
       Close_On_Exception := True;
