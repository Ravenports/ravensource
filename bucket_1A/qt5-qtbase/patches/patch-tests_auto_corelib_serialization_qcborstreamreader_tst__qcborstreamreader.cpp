--- tests/auto/corelib/serialization/qcborstreamreader/tst_qcborstreamreader.cpp.orig	2020-03-27 09:49:31 UTC
+++ tests/auto/corelib/serialization/qcborstreamreader/tst_qcborstreamreader.cpp
@@ -361,7 +361,8 @@ template <typename T> static inline bool
     // converting FP to integral is UB if it can't be represented.;
     Q_STATIC_ASSERT(std::numeric_limits<T>::is_integer);
 
-    double supremum = ldexp(1, std::numeric_limits<T>::digits);
+    double fred = 1;
+    double supremum = ldexp(fred, std::numeric_limits<T>::digits);
     if (v >= supremum)
         return false;
 
