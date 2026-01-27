--- mdb.c.orig	2024-05-21 17:16:06 UTC
+++ mdb.c
@@ -131,6 +131,8 @@ typedef SSIZE_T	ssize_t;
 # define MDB_FDATASYNC		fsync
 #elif defined(ANDROID)
 # define MDB_FDATASYNC		fsync
+#elif defined(__FreeBSD_version) && __FreeBSD_version < 1101000
+# define MDB_FDATASYNC		fsync
 #endif
 
 #ifndef _WIN32
