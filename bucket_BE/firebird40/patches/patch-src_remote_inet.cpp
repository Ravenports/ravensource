--- src/remote/inet.cpp.orig	2022-08-10 09:04:28 UTC
+++ src/remote/inet.cpp
@@ -960,7 +960,7 @@ rem_port* INET_connect(const TEXT* name,
 		gai_hints.ai_family = ((host.hasData() || !ipv6) ? AF_UNSPEC : AF_INET6);
 	gai_hints.ai_socktype = SOCK_STREAM;
 
-#if !defined(WIN_NT) && !defined(__clang__)
+#if !defined(WIN_NT) && !defined(FREEBSD) && !defined(DRAGONFLY)
 	gai_hints.ai_protocol = SOL_TCP;
 #else
 	gai_hints.ai_protocol = IPPROTO_TCP;
@@ -1168,6 +1168,12 @@ static rem_port* listener_socket(rem_por
 
 	inet_ports->registerPort(port);
 
+	char *parent_pid;
+	if (parent_pid = getenv("FB_SIGNAL_PROCESS"))
+	{
+		kill(atoi(parent_pid), SIGUSR1);
+	}
+
 	if (flag & SRVR_multi_client)
 	{
 		// Prevent the generation of dummy keepalive packets on the connect port.
