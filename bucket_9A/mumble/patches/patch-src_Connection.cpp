Fix build with protobuf 34.x

--- src/Connection.cpp.orig	2026-05-17 12:09:23 UTC
+++ src/Connection.cpp
@@ -174,7 +174,7 @@ void Connection::messageToNetwork(const
 	qToBigEndian< quint16 >(static_cast< quint16 >(msgType), &uc[0]);
 	qToBigEndian< quint32 >(static_cast< unsigned int >(len), &uc[2]);
 
-	msg.SerializeToArray(uc + 6, static_cast< int >(len));
+	if (!msg.SerializeToArray(uc + 6, static_cast< int >(len))) {}
 }
 
 void Connection::sendMessage(const ::google::protobuf::Message &msg, Mumble::Protocol::TCPMessageType msgType,
