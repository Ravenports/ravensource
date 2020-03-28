--- projects/libcxx/src/locale.cpp.orig	2020-03-23 15:01:02 UTC
+++ projects/libcxx/src/locale.cpp
@@ -1109,7 +1109,7 @@ ctype<char>::classic_table()  _NOEXCEPT
 const ctype<char>::mask*
 ctype<char>::classic_table()  _NOEXCEPT
 {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
     return _DefaultRuneLocale.__runetype;
 #elif defined(__NetBSD__)
     return _C_ctype_tab_ + 1;
