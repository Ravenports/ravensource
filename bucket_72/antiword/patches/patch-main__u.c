--- main_u.c.orig	2005-01-15 21:08:51.000000000 +0100
+++ main_u.c	2020-06-07 12:05:48.186319000 +0200
@@ -252,7 +252,7 @@
 
 #if !defined(__dos)
 	if (is_locale_utf8()) {
-#if defined(__STDC_ISO_10646__)
+#if defined(__STDC_ISO_10646__) || defined(__APPLE_CC__)
 		/*
 		 * If the user wants UTF-8 and the envirionment variables
 		 * support UTF-8, than set the locale accordingly
@@ -266,7 +266,7 @@
 		} else {
 			(void)setlocale(LC_CTYPE, "C");
 		}
-#endif /* __STDC_ISO_10646__ */
+#endif /* __STDC_ISO_10646__ || __APPLE_CC__ */
 	} else {
 		if (setlocale(LC_CTYPE, "") == NULL) {
 			werr(0, "Can't set the locale! Will use defaults");
