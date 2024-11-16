--- common/db.h.orig	2007-11-18 16:41:42 UTC
+++ common/db.h
@@ -16,7 +16,10 @@
     (env)->remove(env, path, NULL, flags)
 #endif
 
-#if DB_VERSION_MAJOR >= 4 && DB_VERSION_MINOR >= 1
+#if DB_VERSION_MAJOR >= 4 && DB_VERSION_MINOR >= 4
+#define db_open(db,file,type,flags,mode)				\
+    (db)->open(db, NULL, file, NULL, type, flags | DB_CREATE, mode)
+#elif DB_VERSION_MAJOR >= 4 && DB_VERSION_MINOR >= 1
 #define db_open(db,file,type,flags,mode)				\
     (db)->open(db, NULL, file, NULL, type, flags, mode)
 #else
