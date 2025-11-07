--- Source/dvlnet/tcp_server.cpp.orig	2025-11-07 15:53:09 UTC
+++ Source/dvlnet/tcp_server.cpp
@@ -17,7 +17,7 @@ tcp_server::tcp_server(asio::io_context
     : ioc(ioc)
     , pktfty(pktfty)
 {
-	auto addr = asio::ip::address::from_string(bindaddr);
+	auto addr = asio::ip::make_address(bindaddr);
 	auto ep = asio::ip::tcp::endpoint(addr, port);
 	acceptor = std::make_unique<asio::ip::tcp::acceptor>(ioc, ep, true);
 	StartAccept();
