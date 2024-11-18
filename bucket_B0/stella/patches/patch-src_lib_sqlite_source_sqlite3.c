--- src/lib/sqlite/source/sqlite3.c.orig	2024-10-07 19:34:18 UTC
+++ src/lib/sqlite/source/sqlite3.c
@@ -20645,8 +20645,8 @@ SQLITE_PRIVATE int sqlite3HeapNearlyFull
 ** that deal with sqlite3StackAlloc() failures to be unreachable.
 */
 #ifdef SQLITE_USE_ALLOCA
-# define sqlite3StackAllocRaw(D,N)   alloca(N)
-# define sqlite3StackAllocRawNN(D,N) alloca(N)
+# define sqlite3StackAllocRaw(D,N)   __builtin_alloca(N)
+# define sqlite3StackAllocRawNN(D,N) __builtin_alloca(N)
 # define sqlite3StackFree(D,P)
 # define sqlite3StackFreeNN(D,P)
 #else
