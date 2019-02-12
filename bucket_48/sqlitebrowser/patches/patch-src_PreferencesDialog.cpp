--- src/PreferencesDialog.cpp.orig	2019-02-02 13:03:07 UTC
+++ src/PreferencesDialog.cpp
@@ -384,8 +384,7 @@ void PreferencesDialog::removeExtension(
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
-                         "sqlb_*.qm");
+    QDir translationsDir("%%DATADIR%%/translations", "sqlb_*.qm");
 
     QLocale systemLocale = QLocale::system();
 
