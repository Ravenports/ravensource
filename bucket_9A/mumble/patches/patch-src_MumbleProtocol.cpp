Fix build with protobuf 34.x

--- src/MumbleProtocol.cpp.orig	2026-05-17 12:09:23 UTC
+++ src/MumbleProtocol.cpp
@@ -54,7 +54,7 @@ namespace Protocol {
 
 		buffer.resize(serializedSize + offset);
 
-		message.SerializePartialToArray(buffer.data() + offset, static_cast< int >(serializedSize));
+		if (!message.SerializePartialToArray(buffer.data() + offset, static_cast< int >(serializedSize))) {}
 
 		return serializedSize;
 	}
