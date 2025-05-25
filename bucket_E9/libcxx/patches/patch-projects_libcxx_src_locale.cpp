--- projects/libcxx/src/locale.cpp.orig	2025-05-13 22:18:22 UTC
+++ projects/libcxx/src/locale.cpp
@@ -982,7 +982,7 @@ const ctype<char>::mask* ctype<char>::cl
 }
 #else
 const ctype<char>::mask* ctype<char>::classic_table() noexcept {
-#  if defined(__APPLE__) || defined(__FreeBSD__)
+#  if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
   return _DefaultRuneLocale.__runetype;
 #  elif defined(__NetBSD__)
   return _C_ctype_tab_ + 1;
