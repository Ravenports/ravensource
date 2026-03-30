Fix build with protobuf 34.x

--- src/Connection.cpp.orig	2025-10-11 18:24:04 UTC
+++ src/Connection.cpp
@@ -173,7 +173,7 @@ void Connection::messageToNetwork(const
 	qToBigEndian< quint16 >(static_cast< quint16 >(msgType), &uc[0]);
 	qToBigEndian< quint32 >(static_cast< unsigned int >(len), &uc[2]);
 
-	msg.SerializeToArray(uc + 6, static_cast< int >(len));
+	if (!msg.SerializeToArray(uc + 6, static_cast< int >(len))) {}
 }
 
 void Connection::sendMessage(const ::google::protobuf::Message &msg, Mumble::Protocol::TCPMessageType msgType,
