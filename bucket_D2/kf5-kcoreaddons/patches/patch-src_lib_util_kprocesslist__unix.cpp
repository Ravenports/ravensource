--- src/lib/util/kprocesslist_unix.cpp.orig	2023-01-07 00:25:22 UTC
+++ src/lib/util/kprocesslist_unix.cpp
@@ -25,7 +25,12 @@
 #include <QDir>
 #include <QProcess>
 
-#ifdef Q_OS_FREEBSD
+/*
+ * XXX -
+ * This is probably wrong, but we don't have libprocstat(3), so
+ * what other choice do we have? We just reuse what's here.
+ */
+#if defined(Q_OS_FREEBSD) && !defined(__DragonFly__)
 #error This KProcessInfo implementation is not supported on FreeBSD (use procstat)
 #endif
 
