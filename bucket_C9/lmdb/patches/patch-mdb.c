--- mdb.c.orig	2020-10-26 19:00:40 UTC
+++ mdb.c
@@ -132,6 +132,8 @@ typedef SSIZE_T	ssize_t;
 # define MDB_FDATASYNC		fsync
 #elif defined(ANDROID)
 # define MDB_FDATASYNC		fsync
+#elif defined(__FreeBSD_version) && __FreeBSD_version < 1101000
+# define MDB_FDATASYNC		fsync
 #endif
 
 #ifndef _WIN32
