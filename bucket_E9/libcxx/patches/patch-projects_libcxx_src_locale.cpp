--- projects/libcxx/src/locale.cpp.orig	2022-04-29 00:10:18 UTC
+++ projects/libcxx/src/locale.cpp
@@ -1194,7 +1194,7 @@ ctype<char>::classic_table() noexcept
 const ctype<char>::mask*
 ctype<char>::classic_table() noexcept
 {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
     return _DefaultRuneLocale.__runetype;
 #elif defined(__NetBSD__)
     return _C_ctype_tab_ + 1;
