--- epan/conversation.h.orig	2021-03-10 18:21:20 UTC
+++ epan/conversation.h
@@ -12,6 +12,7 @@
 #define __CONVERSATION_H__
 
 #include "ws_symbol_export.h"
+#include "packet.h"			/* for conversation dissector type */
 
 #ifdef __cplusplus
 extern "C" {
@@ -46,8 +47,6 @@ extern "C" {
 /* Flags to handle endpoints */
 #define USE_LAST_ENDPOINT 0x08		/* Use last endpoint created, regardless of type */
 
-#include "packet.h"			/* for conversation dissector type */
-
 /* Types of port numbers Wireshark knows about. */
 typedef enum {
 	ENDPOINT_NONE,			/* no endpoint */
