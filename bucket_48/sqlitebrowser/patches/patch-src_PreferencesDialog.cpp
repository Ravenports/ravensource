--- src/PreferencesDialog.cpp.orig	2019-02-18 05:21:21 UTC
+++ src/PreferencesDialog.cpp
@@ -384,8 +384,7 @@ void PreferencesDialog::removeExtension(
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
-                         "sqlb_*.qm");
+    QDir translationsDir("%%DATADIR%%/translations", "sqlb_*.qm");
 
     QLocale systemLocale = QLocale::system();
 
