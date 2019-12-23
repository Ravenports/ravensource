--- src/corelib/io/qlockfile_unix.cpp.orig	2019-12-07 06:27:07 UTC
+++ src/corelib/io/qlockfile_unix.cpp
@@ -265,9 +265,15 @@ QString QLockFilePrivate::processNameByP
         return QString();
     QString name = QFile::decodeName(kp.p_comm);
 # else
+#  if defined __DragonFly__
+    if (kp.kp_pid != pid)
+        return QString();
+    QString name = QFile::decodeName(kp.kp_comm);
+#  else
     if (kp.ki_pid != pid)
         return QString();
     QString name = QFile::decodeName(kp.ki_comm);
+#  endif
 # endif
     return name;
 
