On NetBSD we see "Error sending IPC message: Message too long" due to
the use of sendmsg with a large message body (EMSGSIZE).

WebKit already uses shared memory to communicate the message body when
the message is too large, so force it to always use this method to avoid
encountering EMSGSIZE.

--- Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp.orig	2025-08-29 11:47:56 UTC
+++ Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp
@@ -71,6 +71,10 @@
 
 WTF_ALLOW_UNSAFE_BUFFER_USAGE_BEGIN // Unix port
 
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL	0
+#endif
+
 namespace IPC {
 
 static const size_t messageMaxSize = 4096;
@@ -513,8 +517,12 @@ bool Connection::sendOutgoingMessage(Uni
         return false;
     }
 
+#if 0
     size_t messageSizeWithBodyInline = sizeof(MessageInfo) + (outputMessage.attachments().size() * sizeof(AttachmentInfo)) + outputMessage.bodySize();
     if (messageSizeWithBodyInline > messageMaxSize && outputMessage.bodySize()) {
+#else
+    {
+#endif
         RefPtr oolMessageBody = WebCore::SharedMemory::allocate(outputMessage.bodySize());
         if (!oolMessageBody)
             return false;
