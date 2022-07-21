--- common/conf_post.h.orig	2022-06-14 12:56:22 UTC
+++ common/conf_post.h
@@ -67,18 +67,4 @@ typedef int ssize_t;
 #  define PRETEND_USE(expr) ((void)(expr))
 #endif /* PRETEND_USE */
 
-// It's complicated to really detect gnu gcc because other compilers define __GNUC__
-// See stackoverflow questions/38499462/how-to-tell-clang-to-stop-pretending-to-be-other-compilers
-#if defined(__GNUC__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
-#define REAL_GCC   __GNUC__ // probably
-#endif
-
-#ifdef REAL_GCC
-// Older gcc versions pretended to supply std::regex, but the resulting programs mostly crashed.
-#include <features.h>
-#if ! __GNUC_PREREQ(6,0)
-#define NO_STD_REGEX 1
-#endif
-#endif
-
 #endif /* INCLUDED */
