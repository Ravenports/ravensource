--- common/putil.cpp.orig	2025-03-13 18:31:23 UTC
+++ common/putil.cpp
@@ -2032,11 +2032,6 @@ remapPlatformDependentCodepage(const cha
          */
         name = "UTF-8";
     }
-#elif U_PLATFORM == U_PF_BSD
-    if (uprv_strcmp(name, "CP949") == 0) {
-        /* Remap CP949 to a similar codepage to avoid issues with backslash and won symbol. */
-        name = "EUC-KR";
-    }
 #elif U_PLATFORM == U_PF_HPUX
     if (locale != nullptr && uprv_strcmp(locale, "zh_HK") == 0 && uprv_strcmp(name, "big5") == 0) {
         /* HP decided to extend big5 as hkbig5 even though it's not compatible :-( */
@@ -2192,7 +2187,7 @@ int_getDefaultCodepage()
        nl_langinfo may use the same buffer as setlocale. */
     {
         const char *codeset = nl_langinfo(U_NL_LANGINFO_CODESET);
-#if U_PLATFORM_IS_DARWIN_BASED || U_PLATFORM_IS_LINUX_BASED
+#if U_PLATFORM_IS_DARWIN_BASED || U_PLATFORM_IS_LINUX_BASED || U_PLATFORM == U_PF_BSD
         /*
          * On Linux and MacOSX, ensure that default codepage for non C/POSIX locale is UTF-8
          * instead of ASCII.
