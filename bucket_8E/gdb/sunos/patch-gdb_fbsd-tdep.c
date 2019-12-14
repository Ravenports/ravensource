--- gdb/fbsd-tdep.c.intermediate	2019-12-14 06:50:12 UTC
+++ gdb/fbsd-tdep.c
@@ -1035,12 +1035,12 @@ fbsd_info_proc_files_entry (int kf_type,
 
 	    /* For local sockets, print out the first non-nul path
 	       rather than both paths.  */
-	    const struct fbsd_sockaddr_un *sun
+	    const struct fbsd_sockaddr_un *xsunx
 	      = reinterpret_cast<const struct fbsd_sockaddr_un *> (kf_sa_local);
-	    if (sun->sun_path[0] == 0)
-	      sun = reinterpret_cast<const struct fbsd_sockaddr_un *>
+	    if (xsunx->sun_path[0] == 0)
+	      xsunx = reinterpret_cast<const struct fbsd_sockaddr_un *>
 		(kf_sa_peer);
-	    printf_filtered ("%s", sun->sun_path);
+	    printf_filtered ("%s", xsunx->sun_path);
 	    break;
 	  }
 	case FBSD_AF_INET:
