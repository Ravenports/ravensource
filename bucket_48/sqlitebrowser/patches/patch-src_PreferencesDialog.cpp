--- src/PreferencesDialog.cpp.orig	2026-11-07 00:41:11 UTC
+++ src/PreferencesDialog.cpp
@@ -414,8 +414,7 @@ void PreferencesDialog::createBuiltinExt
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
-                         "sqlb_*.qm");
+    QDir translationsDir("%%DATADIR%%/translations", "sqlb_*.qm");
 
     QLocale systemLocale(Settings::systemLanguage());
 
