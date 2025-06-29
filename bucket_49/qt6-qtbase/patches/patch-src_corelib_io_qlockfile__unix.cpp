--- src/corelib/io/qlockfile_unix.cpp.orig	2025-05-28 10:22:57 UTC
+++ src/corelib/io/qlockfile_unix.cpp
@@ -251,9 +251,15 @@ QString QLockFilePrivate::processNameByP
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
 #elif defined(Q_OS_QNX)
