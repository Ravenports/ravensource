--- erts/emulator/sys/unix/erl_unix_sys.h.orig	2017-09-25 19:10:38 UTC
+++ erts/emulator/sys/unix/erl_unix_sys.h
@@ -332,26 +332,6 @@ extern void erts_sys_unix_later_init(voi
  * Handling of floating point exceptions.
  */
 
-#ifdef USE_ISINF_ISNAN		/* simulate finite() */
-#  define isfinite(f) (!isinf(f) && !isnan(f))
-#  define HAVE_ISFINITE
-#elif (defined(__GNUC__) && !defined(__llvm__)) && defined(HAVE_FINITE)
-/* We use finite in gcc as it emits assembler instead of
-   the function call that isfinite emits. The assembler is
-   significantly faster. */
-#  ifdef isfinite
-#     undef isfinite
-#  endif
-#  define isfinite finite
-#  ifndef HAVE_ISFINITE
-#    define HAVE_ISFINITE
-#  endif
-#elif defined(isfinite) && !defined(HAVE_ISFINITE)
-#  define HAVE_ISFINITE
-#elif !defined(HAVE_ISFINITE) && defined(HAVE_FINITE)
-#  define isfinite finite
-#  define HAVE_ISFINITE
-#endif
 
 #define erts_isfinite isfinite
 
