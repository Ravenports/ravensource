--- qmake/generators/unix/unixmake2.cpp.orig	2020-03-27 09:49:31 UTC
+++ qmake/generators/unix/unixmake2.cpp
@@ -191,12 +191,12 @@ UnixMakefileGenerator::writeMakeParts(QT
     t << "####### Compiler, tools and options\n\n";
     t << "CC            = " << var("QMAKE_CC") << Qt::endl;
     t << "CXX           = " << var("QMAKE_CXX") << Qt::endl;
-    t << "DEFINES       = "
+    t << "DEFINES       += "
       << varGlue("PRL_EXPORT_DEFINES","-D"," -D"," ")
       << varGlue("DEFINES","-D"," -D","") << Qt::endl;
-    t << "CFLAGS        = " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
-    t << "CXXFLAGS      = " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
-    t << "INCPATH       =";
+    t << "CFLAGS        += " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
+    t << "CXXFLAGS      += " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
+    t << "INCPATH       +=";
     {
         QString isystem = var("QMAKE_CFLAGS_ISYSTEM");
         const ProStringList &incs = project->values("INCLUDEPATH");
@@ -220,8 +220,8 @@ UnixMakefileGenerator::writeMakeParts(QT
 
     if(!project->isActiveConfig("staticlib")) {
         t << "LINK          = " << var("QMAKE_LINK") << Qt::endl;
-        t << "LFLAGS        = " << var("QMAKE_LFLAGS") << Qt::endl;
-        t << "LIBS          = $(SUBLIBS) " << fixLibFlags("LIBS").join(' ') << ' '
+        t << "LFLAGS        += " << var("QMAKE_LFLAGS") << Qt::endl;
+        t << "LIBS          += $(SUBLIBS) " << fixLibFlags("LIBS").join(' ') << ' '
                                            << fixLibFlags("LIBS_PRIVATE").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS_PRIVATE").join(' ') << Qt::endl;
