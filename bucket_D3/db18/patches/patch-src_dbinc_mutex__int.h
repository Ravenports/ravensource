--- src/dbinc/mutex_int.h.orig	2020-05-29 17:58:22 UTC
+++ src/dbinc/mutex_int.h
@@ -9,6 +9,10 @@
 #ifndef _DB_MUTEX_INT_H_
 #define	_DB_MUTEX_INT_H_
 
+#if defined __DragonFly__ || defined __FreeBSD__
+#include <machine/atomic.h>
+#endif
+
 #include "dbinc/atomic.h"
 
 #if defined(__cplusplus)
@@ -487,11 +491,11 @@ typedef unsigned int tsl_t;
 #define	MUTEX_UNSET(tsl)	(*(volatile tsl_t *)(tsl) = 0)
 #define	MUTEX_INIT(tsl)         (MUTEX_UNSET(tsl), 0)
 #define	MUTEX_MEMBAR(x) \
-	({ __asm__ volatile ("dsb"); })
+	dsb(x)
 #define	MEMBAR_ENTER() \
-	({ __asm__ volatile ("dsb"); })
+	dsb()
 #define	MEMBAR_EXIT() \
-	({ __asm__ volatile ("dsb"); })
+	dsb()
 #endif
 #endif
 
@@ -633,7 +637,7 @@ MUTEX_SET(int *tsl)  {
 	 : "=&r" (__r), "+r" (tsl)
 	 :
 	 : "cr0", "memory");
-	 return (int)tsl;
+	 return (tsl != 0);
 }
 
 static inline int
