--- dbus/dbus-connection.c.orig	2023-06-06 13:00:36 UTC
+++ dbus/dbus-connection.c
@@ -2397,7 +2397,7 @@ _dbus_connection_block_pending_call (DBu
   DBusConnection *connection;
   dbus_uint32_t client_serial;
   DBusTimeout *timeout;
-  int timeout_milliseconds, elapsed_milliseconds;
+  int timeout_milliseconds, elapsed_milliseconds, remain_milliseconds;
 
   _dbus_assert (pending != NULL);
 
@@ -2478,7 +2478,11 @@ _dbus_connection_block_pending_call (DBu
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
@@ -2506,7 +2510,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2515,7 +2519,7 @@ _dbus_connection_block_pending_call (DBu
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
@@ -2524,7 +2528,7 @@ _dbus_connection_block_pending_call (DBu
     _dbus_verbose ("dbus_connection_send_with_reply_and_block(): clock set backward\n");
   else if (elapsed_milliseconds < timeout_milliseconds)
     {
-      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", timeout_milliseconds - elapsed_milliseconds);
+      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", remain_milliseconds);
       
       if (status == DBUS_DISPATCH_NEED_MEMORY)
         {
@@ -2534,7 +2538,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2543,7 +2547,7 @@ _dbus_connection_block_pending_call (DBu
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
