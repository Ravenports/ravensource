--- src/PreferencesDialog.cpp.orig	2020-06-14 04:08:29 UTC
+++ src/PreferencesDialog.cpp
@@ -410,8 +410,7 @@ void PreferencesDialog::removeExtension(
 
 void PreferencesDialog::fillLanguageBox()
 {
-    QDir translationsDir(QCoreApplication::applicationDirPath() + "/translations",
-                         "sqlb_*.qm");
+    QDir translationsDir("%%DATADIR%%/translations", "sqlb_*.qm");
 
     QLocale systemLocale = QLocale::system();
 
