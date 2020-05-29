--- gdb/fbsd-nat.c.orig	2020-05-23 21:10:29 UTC
+++ gdb/fbsd-nat.c
@@ -1176,6 +1176,14 @@ fbsd_nat_target::resume (ptid_t ptid, in
       /* If ptid is a specific LWP, suspend all other LWPs in the process.  */
       inferior *inf = find_inferior_ptid (ptid);
 
+#ifndef PT_LWP_EVENTS
+      /* When LWP events are not supported, a new thread might already be
+	 running that has not yet reported an event when GDB wishes to
+	 only run a single thread.  Force an update of the thread list
+	 to ensure that any such threads are suspended before the process
+	 is resumed.  */
+      fbsd_add_threads (ptid.pid ());
+#endif
       for (thread_info *tp : inf->non_exited_threads ())
         {
 	  int request;
