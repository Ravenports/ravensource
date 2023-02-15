--- dbus/dbus-connection.c.orig	2023-01-30 09:57:39 UTC
+++ dbus/dbus-connection.c
@@ -2388,7 +2388,7 @@ _dbus_connection_block_pending_call (DBu
   DBusConnection *connection;
   dbus_uint32_t client_serial;
   DBusTimeout *timeout;
-  int timeout_milliseconds, elapsed_milliseconds;
+  int timeout_milliseconds, elapsed_milliseconds, remain_milliseconds;
 
   _dbus_assert (pending != NULL);
 
@@ -2469,7 +2469,11 @@ _dbus_connection_block_pending_call (DBu
   _dbus_get_monotonic_time (&tv_sec, &tv_usec);
   elapsed_milliseconds = (tv_sec - start_tv_sec) * 1000 +
 	  (tv_usec - start_tv_usec) / 1000;
-  
+  if (timeout_milliseconds != -1)
+    remain_milliseconds = timeout_milliseconds - elapsed_milliseconds;
+  else
+    remain_milliseconds = -1;
+
   if (!_dbus_connection_get_is_connected_unlocked (connection))
     {
       DBusMessage *error_msg;
@@ -2497,7 +2501,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2506,7 +2510,7 @@ _dbus_connection_block_pending_call (DBu
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
@@ -2515,7 +2519,7 @@ _dbus_connection_block_pending_call (DBu
     _dbus_verbose ("dbus_connection_send_with_reply_and_block(): clock set backward\n");
   else if (elapsed_milliseconds < timeout_milliseconds)
     {
-      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", timeout_milliseconds - elapsed_milliseconds);
+      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", remain_milliseconds);
       
       if (status == DBUS_DISPATCH_NEED_MEMORY)
         {
@@ -2525,7 +2529,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2534,7 +2538,7 @@ _dbus_connection_block_pending_call (DBu
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
