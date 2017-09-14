--- lib/cdefs.h.orig	2017-09-12 14:13:24 UTC
+++ lib/cdefs.h
@@ -282,13 +282,6 @@
 # define __attribute_format_strfmon__(a,b) /* Ignore */
 #endif
 
-/* The nonull function attribute allows to mark pointer parameters which
-   must not be NULL.  */
-#if __GNUC_PREREQ (3,3)
-# define __nonnull(params) __attribute__ ((__nonnull__ params))
-#else
-# define __nonnull(params)
-#endif
 
 /* If fortification mode, we warn about unused results of certain
    function calls which can lead to problems.  */
