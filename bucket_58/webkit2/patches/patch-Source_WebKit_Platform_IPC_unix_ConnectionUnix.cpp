$NetBSD: patch-Source_WebKit_Platform_IPC_unix_ConnectionUnix.cpp,v 1.3 2021/01/12 15:21:31 jperkin Exp $

On NetBSD we see "Error sending IPC message: Message too long" due to
the use of sendmsg with a large message body (EMSGSIZE).

WebKit already uses shared memory to communicate the message body when
the message is too large, so force it to always use this method to avoid
encountering EMSGSIZE.

--- Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp.orig	2022-02-23 11:41:51 UTC
+++ Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp
@@ -61,6 +61,10 @@
 #endif
 #endif // SOCK_SEQPACKET
 
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL	0
+#endif
+
 namespace IPC {
 
 static const size_t messageMaxSize = 4096;
@@ -442,8 +446,12 @@ bool Connection::sendOutgoingMessage(Uni
         return false;
     }
 
+#if 0
     size_t messageSizeWithBodyInline = sizeof(MessageInfo) + (outputMessage.attachments().size() * sizeof(AttachmentInfo)) + outputMessage.bodySize();
     if (messageSizeWithBodyInline > messageMaxSize && outputMessage.bodySize()) {
+#else
+    {
+#endif
         RefPtr<WebKit::SharedMemory> oolMessageBody = WebKit::SharedMemory::allocate(encoder->bufferSize());
         if (!oolMessageBody)
             return false;
