--- src/PreferencesDialog.cpp.orig	2024-10-15 07:36:40 UTC
+++ src/PreferencesDialog.cpp
@@ -505,8 +505,7 @@ void PreferencesDialog::createBuiltinExt
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
-                         "sqlb_*.qm");
+    QDir translationsDir("%%DATADIR%%/translations", "sqlb_*.qm");
 
     QLocale systemLocale = QLocale::system();
 
