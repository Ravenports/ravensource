--- gnulib/import/stddef.in.h.orig	2021-04-25 04:06:26 UTC
+++ gnulib/import/stddef.in.h
@@ -90,7 +90,7 @@
 #if defined _MSC_VER && defined __cplusplus
 # include <cstddef>
 #else
-# if ! (@HAVE_MAX_ALIGN_T@ || defined _GCC_MAX_ALIGN_T)
+# if 0
 #  if !GNULIB_defined_max_align_t
 /* On the x86, the maximum storage alignment of double, long, etc. is 4,
    but GCC's C11 ABI for x86 says that max_align_t has an alignment of 8,
