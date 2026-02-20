--- ext/ed.cpp.orig	2026-02-20 16:37:02 UTC
+++ ext/ed.cpp
@@ -1084,7 +1084,7 @@ void ConnectionDescriptor::_WriteOutboun
 
 	for(int i = 0; i < iovcnt; i++){
 		OutboundPage *op = &(OutboundPages[i]);
-		#ifdef CC_SUNWspro
+		#ifdef __sun__
 		// TODO: The void * cast works fine on Solaris 11, but
 		// I don't know at what point that changed from older Solaris.
 		iov[i].iov_base = (char *)(op->Buffer + op->Offset);
