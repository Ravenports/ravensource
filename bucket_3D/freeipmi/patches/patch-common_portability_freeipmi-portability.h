--- common/portability/freeipmi-portability.h.orig	2024-01-27 21:42:42 UTC
+++ common/portability/freeipmi-portability.h
@@ -75,6 +75,10 @@
 #define O_SYNC  O_FSYNC
 #endif
 
+#if !defined(AI_V4MAPPED)
+#define AI_V4MAPPED	0
+#endif
+
 /* FreeBSD don't have log2(), exp10() and exp2() */
 #ifndef HAVE_LOG2
 /* Cygwin has a log2 macro to already handle portability */
