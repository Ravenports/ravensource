--- Xtrans.c.orig	2024-10-12 20:45:16 UTC
+++ Xtrans.c
@@ -162,7 +162,7 @@ TRANS(SelectTransport) (const char *prot
     strncpy (protobuf, protocol, PROTOBUFSIZE - 1);
     protobuf[PROTOBUFSIZE-1] = '\0';
 
-    for (i = 0; i < PROTOBUFSIZE && protobuf[i] != '\0'; i++)
+    for (unsigned int i = 0; i < PROTOBUFSIZE && protobuf[i] != '\0'; i++)
 	if (isupper ((unsigned char)protobuf[i]))
 	    protobuf[i] = tolower ((unsigned char)protobuf[i]);
 #endif
