Rename structure to avoid name collision on solaris.

--- src/nvim/lib/queue_defs.h.orig	2026-03-29 16:16:17 UTC
+++ src/nvim/lib/queue_defs.h
@@ -21,9 +21,9 @@
 
 #include <stddef.h>
 
-typedef struct queue {
-  struct queue *next;
-  struct queue *prev;
+typedef struct neo_queue {
+  struct neo_queue *next;
+  struct neo_queue *prev;
 } QUEUE;
 
 #include "lib/queue_defs.h.inline.generated.h"
