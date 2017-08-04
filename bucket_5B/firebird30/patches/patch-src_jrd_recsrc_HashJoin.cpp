--- src/jrd/recsrc/HashJoin.cpp.orig	2017-03-21 09:11:36 UTC
+++ src/jrd/recsrc/HashJoin.cpp
@@ -53,7 +53,7 @@ namespace
 	  qsort_compare_callback compare;
 	};
 
-#if defined(DARWIN) // || defined(FREEBSD)
+#if defined(DARWIN) || defined(FREEBSD)
 #undef HAVE_QSORT_R
 #endif
 
