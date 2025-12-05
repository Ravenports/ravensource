--- libcxx/include/__cxx03/stdlib.h.orig	2025-12-01 12:58:50 UTC
+++ libcxx/include/__cxx03/stdlib.h
@@ -141,7 +141,7 @@ _LIBCPP_NODISCARD inline _LIBCPP_HIDE_FR
 // MSVCRT already has the correct prototype in <stdlib.h> if __cplusplus is defined
 #    if !defined(_LIBCPP_MSVCRT)
 inline _LIBCPP_HIDE_FROM_ABI ldiv_t div(long __x, long __y) _NOEXCEPT { return ::ldiv(__x, __y); }
-#      if !(defined(__FreeBSD__) && !defined(__LONG_LONG_SUPPORTED))
+#      if !((defined(__FreeBSD__) || defined(__DragonFly__)) && !defined(__LONG_LONG_SUPPORTED))
 inline _LIBCPP_HIDE_FROM_ABI lldiv_t div(long long __x, long long __y) _NOEXCEPT { return ::lldiv(__x, __y); }
 #      endif
 #    endif // _LIBCPP_MSVCRT
