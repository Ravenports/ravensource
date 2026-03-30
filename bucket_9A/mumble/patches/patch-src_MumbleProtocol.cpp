Fix build with protobuf 34.x

--- src/MumbleProtocol.cpp.orig	2025-10-11 18:24:04 UTC
+++ src/MumbleProtocol.cpp
@@ -54,7 +54,7 @@ namespace Protocol {
 
 		buffer.resize(serializedSize + offset);
 
-		message.SerializePartialToArray(buffer.data() + offset, static_cast< int >(serializedSize));
+		if (!message.SerializePartialToArray(buffer.data() + offset, static_cast< int >(serializedSize))) {}
 
 		return serializedSize;
 	}
