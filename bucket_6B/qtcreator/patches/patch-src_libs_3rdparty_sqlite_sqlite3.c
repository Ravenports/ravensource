--- src/libs/3rdparty/sqlite/sqlite3.c.orig	2025-06-17 17:36:50 UTC
+++ src/libs/3rdparty/sqlite/sqlite3.c
@@ -14486,7 +14486,7 @@ struct fts5_api {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE)
 #  define _XOPEN_SOURCE 600
 #endif
 
