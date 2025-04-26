$NetBSD: patch-src_common_locale.cpp,v 1.2 2020/05/31 11:34:15 adam Exp $

Remove broken SunOS section that is no longer needed.
https://gitlab.com/mbunkus/mkvtoolnix/issues/2450

--- src/common/locale.cpp.orig	2025-04-26 13:52:13 UTC
+++ src/common/locale.cpp
@@ -286,12 +286,6 @@ get_local_charset() {
 
 #if defined(COMP_MINGW) || defined(COMP_MSC)
   lc_charset = fmt::format("CP{0}", GetACP());
-#elif defined(SYS_SOLARIS)
-  int i;
-
-  lc_charset = nl_langinfo(CODESET);
-  if (mtx::string::parse_number(lc_charset, i))
-    lc_charset = "ISO"s + lc_charset + "-US"s;
 #elif HAVE_NL_LANGINFO
   lc_charset = nl_langinfo(CODESET);
 #elif HAVE_LOCALE_CHARSET
