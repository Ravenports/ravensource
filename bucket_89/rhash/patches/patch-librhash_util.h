NetBSD: Avoid choosing aligned_alloc() when it's not present, such as CentOS 6
        with lang/gcc7.

--- librhash/util.h.orig	2022-06-14 20:25:13 UTC
+++ librhash/util.h
@@ -42,6 +42,7 @@ extern "C" {
 # define rhash_aligned_free(ptr) _aligned_free(ptr)
 
 #elif !defined(NO_STDC_ALIGNED_ALLOC) && (__STDC_VERSION__ >= 201112L || defined(_ISOC11_SOURCE)) \
+	&& !defined(NOPE_DOES_NOT_HAS_STDC_ALIGNED_ALLOC) \
 	&& !defined(__APPLE__) && (!defined(__ANDROID_API__) || __ANDROID_API__ >= 28)
 
 # define HAS_STDC_ALIGNED_ALLOC
