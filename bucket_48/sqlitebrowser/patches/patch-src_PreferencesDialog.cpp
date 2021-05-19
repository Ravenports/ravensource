--- src/PreferencesDialog.cpp.orig	2021-05-02 14:08:53 UTC
+++ src/PreferencesDialog.cpp
@@ -411,8 +411,7 @@ void PreferencesDialog::removeExtension(
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
-                         "sqlb_*.qm");
+    QDir translationsDir("%%DATADIR%%/translations", "sqlb_*.qm");
 
     QLocale systemLocale = QLocale::system();
 
