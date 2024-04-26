On NetBSD we see "Error sending IPC message: Message too long" due to
the use of sendmsg with a large message body (EMSGSIZE).

WebKit already uses shared memory to communicate the message body when
the message is too large, so force it to always use this method to avoid
encountering EMSGSIZE.

--- Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp.orig	2024-03-16 06:45:50 UTC
+++ Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp
@@ -62,6 +62,10 @@
 #endif
 #endif // SOCK_SEQPACKET
 
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL	0
+#endif
+
 namespace IPC {
 
 static const size_t messageMaxSize = 4096;
@@ -406,8 +410,12 @@ bool Connection::sendOutgoingMessage(Uni
         return false;
     }
 
+#if 0
     size_t messageSizeWithBodyInline = sizeof(MessageInfo) + (outputMessage.attachments().size() * sizeof(AttachmentInfo)) + outputMessage.bodySize();
     if (messageSizeWithBodyInline > messageMaxSize && outputMessage.bodySize()) {
+#else
+    {
+#endif
         RefPtr<WebCore::SharedMemory> oolMessageBody = WebCore::SharedMemory::allocate(outputMessage.bodySize());
         if (!oolMessageBody)
             return false;
