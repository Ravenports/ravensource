--- src/anet-sockets-inet.adb.orig	2019-10-30 14:36:44 UTC
+++ src/anet-sockets-inet.adb
@@ -69,7 +69,7 @@ package body Anet.Sockets.Inet is
       Res  : C.int;
       Sock : Thin.Inet.Sockaddr_In_Type
         (Family => Socket_Families.Family_Inet);
-      Len  : aliased C.int := Sock'Size / 8;
+      Len  : aliased C.int := Thin.Inet.Sockaddr_In_Size;
    begin
       New_Socket.Sock_FD := -1;
       Src := (Addr => Any_Addr,
@@ -116,7 +116,7 @@ package body Anet.Sockets.Inet is
       Res  : C.int;
       Sock : Thin.Inet.Sockaddr_In_Type
         (Family => Socket_Families.Family_Inet6);
-      Len  : aliased C.int := Sock'Size / 8;
+      Len  : aliased C.int := Thin.Inet.Sockaddr_In6_Size;
    begin
       New_Socket.Sock_FD := -1;
       Src := (Addr => Any_Addr_V6,
@@ -173,7 +173,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Bind
            (S       => Socket.Sock_FD,
             Name    => Sockaddr'Address,
-            Namelen => Sockaddr'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In_Size),
          Message => "Unable to bind IPv4 socket to " & To_String
            (Address => Address) & "," & Port'Img);
    end Bind;
@@ -200,7 +200,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Bind
            (S       => Socket.Sock_FD,
             Name    => Sockaddr'Address,
-            Namelen => Sockaddr'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In6_Size),
          Message => "Unable to bind IPv6 socket to " & To_String
            (Address => Address) & "," & Port'Img);
    end Bind;
@@ -220,7 +220,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Connect
            (S       => Socket.Sock_FD,
             Name    => Dst'Address,
-            Namelen => Dst'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In_Size),
          Message => "Unable to connect socket to address " & To_String
            (Address => Address) & " (" & Port'Img & " )");
    end Connect;
@@ -240,7 +240,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Connect
            (S       => Socket.Sock_FD,
             Name    => Dst'Address,
-            Namelen => Dst'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In6_Size),
          Message => "Unable to connect socket to address " & To_String
            (Address => Address) & " (" & Port'Img & " )");
    end Connect;
@@ -478,7 +478,7 @@ package body Anet.Sockets.Inet is
          Len   => Item'Length,
          Flags => Constants.Sys.MSG_NOSIGNAL,
          To    => Dst'Address,
-         Tolen => Dst'Size / 8);
+         Tolen => Thin.Inet.Sockaddr_In_Size);
 
       Errno.Check_Or_Raise
         (Result  => C.int (Res),
@@ -510,7 +510,7 @@ package body Anet.Sockets.Inet is
          Len   => Item'Length,
          Flags => Constants.Sys.MSG_NOSIGNAL,
          To    => Dst'Address,
-         Tolen => Dst'Size / 8);
+         Tolen => Thin.Inet.Sockaddr_In6_Size);
 
       Errno.Check_Or_Raise
         (Result  => C.int (Res),
