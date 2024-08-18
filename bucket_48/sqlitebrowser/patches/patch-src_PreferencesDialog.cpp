--- src/PreferencesDialog.cpp.orig	2024-06-29 06:33:40 UTC
+++ src/PreferencesDialog.cpp
@@ -505,8 +505,7 @@ void PreferencesDialog::createBuiltinExt
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
-                         "sqlb_*.qm");
+    QDir translationsDir("%%DATADIR%%/translations", "sqlb_*.qm");
 
     QLocale systemLocale = QLocale::system();
 
