--- src/gpu/GrAutoLocaleSetter.h.orig	2020-03-19 21:10:56 UTC
+++ src/gpu/GrAutoLocaleSetter.h
@@ -49,7 +49,7 @@ public:
         } else {
             fShouldRestoreLocale = false;
         }
-#elif HAVE_LOCALE_T
+#elif HAVE_LOCALE_T && !defined __NetBSD__
 #if HAVE_XLOCALE
         // In xlocale nullptr means the C locale.
         if (0 == strcmp(name, "C")) {
@@ -73,7 +73,7 @@ public:
             setlocale(LC_ALL, fOldLocale.c_str());
         }
         _configthreadlocale(fOldPerThreadLocale);
-#elif HAVE_LOCALE_T
+#elif HAVE_LOCALE_T && !defined __NetBSD__
         if (fLocale) {
              uselocale(fOldLocale);
              freelocale(fLocale);
