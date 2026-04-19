--- src/util/xxhash.h.orig	2026-03-18 15:54:10 UTC
+++ src/util/xxhash.h
@@ -1704,7 +1704,7 @@ struct XXH64_state_s {
 
 #ifndef XXH_NO_XXH3
 
-#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) /* >= C11 */
+#if !defined(__sun__) && (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) /* >= C11 */
 #  define XXH_ALIGN(n)      _Alignas(n)
 #elif defined(__cplusplus) && (__cplusplus >= 201103L) /* >= C++11 */
 /* In C++ alignas() is a keyword */
@@ -2496,7 +2496,7 @@ static void* XXH_memcpy(void* dest, cons
 
 /* note: use after variable declarations */
 #ifndef XXH_STATIC_ASSERT
-#  if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)    /* C11 */
+#  if !defined(__sun__) && (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L))    /* C11 */
 #    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { _Static_assert((c),m); } while(0)
 #  elif defined(__cplusplus) && (__cplusplus >= 201103L)            /* C++11 */
 #    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { static_assert((c),m); } while(0)
