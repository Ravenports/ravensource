--- mdb.c.orig	2026-01-26 19:02:01 UTC
+++ mdb.c
@@ -138,6 +138,8 @@ typedef SSIZE_T	ssize_t;
 #elif defined(__HAIKU__)
 # define MDB_USE_POSIX_SEM	1
 # define MDB_FDATASYNC		fsync
+#elif defined(__FreeBSD_version) && __FreeBSD_version < 1101000
+# define MDB_FDATASYNC		fsync
 #endif
 
 /* NetBSD does not define union semun in sys/sem.h */
