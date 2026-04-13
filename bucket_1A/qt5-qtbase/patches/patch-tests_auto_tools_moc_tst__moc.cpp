Another example of coders picking the stupidest possible names for variables.
Fixes NetBSD and SunOS.

--- tests/auto/tools/moc/tst_moc.cpp.orig	2025-06-05 14:07:26 UTC
+++ tests/auto/tools/moc/tst_moc.cpp
@@ -760,8 +760,8 @@ private:
 
 #define VERIFY_NO_ERRORS(proc) do { \
         auto &&p = proc; \
-        const QByteArray stderr = p.readAllStandardError(); \
-        QVERIFY2(stderr.isEmpty(), stderr.data()); \
+        const QByteArray xstderr = p.readAllStandardError(); \
+        QVERIFY2(xstderr.isEmpty(), xstderr.data()); \
         QCOMPARE(p.exitCode(), 0); \
     } while (false)
 
