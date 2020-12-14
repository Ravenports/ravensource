--- simd-support/taint.c.orig	2020-12-10 12:02:44 UTC
+++ simd-support/taint.c
@@ -40,4 +40,8 @@ R *X(join_taint)(R *p1, R *p2)
      A(UNTAINT(p1) == UNTAINT(p2));
      return (R *)(PTRINT(p1) | PTRINT(p2));
 }
+#else
+# ifdef __sun__
+int Solaris_requires_a_symbol= 0;
+# endif
 #endif
