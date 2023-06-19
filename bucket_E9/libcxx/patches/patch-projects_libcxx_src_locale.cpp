--- projects/libcxx/src/locale.cpp.orig	2023-06-10 22:58:16 UTC
+++ projects/libcxx/src/locale.cpp
@@ -1183,7 +1183,7 @@ ctype<char>::classic_table() noexcept
 const ctype<char>::mask*
 ctype<char>::classic_table() noexcept
 {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
     return _DefaultRuneLocale.__runetype;
 #elif defined(__NetBSD__)
     return _C_ctype_tab_ + 1;
