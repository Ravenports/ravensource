--- gnulib/import/stddef.in.h.orig	2022-01-16 11:19:03 UTC
+++ gnulib/import/stddef.in.h
@@ -107,7 +107,7 @@ typedef long max_align_t;
 #if defined _MSC_VER && defined __cplusplus
 # include <cstddef>
 #else
-# if ! (@HAVE_MAX_ALIGN_T@ || defined _GCC_MAX_ALIGN_T)
+# if 0
 #  if !GNULIB_defined_max_align_t
 /* On the x86, the maximum storage alignment of double, long, etc. is 4,
    but GCC's C11 ABI for x86 says that max_align_t has an alignment of 8,
