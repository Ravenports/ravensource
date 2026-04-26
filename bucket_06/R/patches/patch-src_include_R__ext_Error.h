--- src/include/R_ext/Error.h.orig	2026-03-26 23:02:03 UTC
+++ src/include/R_ext/Error.h
@@ -39,6 +39,12 @@ extern "C" {
  * OTOH, '_Noreturn' is an obsolescent (in C23) function specifier.
  */
 #if defined NORET
+#elif defined(__cplusplus)
+# if __cplusplus >= 201103L
+#  define NORET [[noreturn]]
+# else
+#  define NORET __attribute__((noreturn))
+# endif
 #elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202301L)
 // gcc 15 LLVM clang 19- and Apple clang 17
 # define NORET [[noreturn]]
