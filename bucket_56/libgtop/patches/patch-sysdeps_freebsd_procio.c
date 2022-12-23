--- sysdeps/freebsd/procio.c.orig	2019-02-04 20:15:22 UTC
+++ sysdeps/freebsd/procio.c
@@ -74,7 +74,9 @@ glibtop_get_proc_io_p (glibtop *server,
 
 	   FIXME: seems the blocksize is 1024 but ...
 	*/
+#ifndef __DragonFly__
 	buf->disk_rbytes = pinfo->ki_rusage.ru_inblock << 10;
 	buf->disk_wbytes = pinfo->ki_rusage.ru_oublock << 10;
 	buf->flags = _glibtop_sysdeps_proc_io;
+#endif
 }
