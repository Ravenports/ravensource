--- src/Application.cpp.orig	2017-09-20 13:59:51 UTC
+++ src/Application.cpp
@@ -27,8 +27,8 @@ Application::Application(int& argc, char
 
     // First of all try to load the application translation file.
     m_translatorApp = new QTranslator(this);
-    ok = m_translatorApp->load("sqlb_" + name,
-                               QCoreApplication::applicationDirPath() + "/translations");
+    QString trans_dir = "%%DATADIR%%/translations";
+    ok = m_translatorApp->load("sqlb_" + name, trans_dir);
     // If failed then try to load .qm file from resources
     if (ok == false) {
         ok = m_translatorApp->load("sqlb_" + name, ":/translations");
