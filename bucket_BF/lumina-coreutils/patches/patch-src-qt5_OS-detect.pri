--- ../../src-qt5/OS-detect.pri.orig	2021-12-26 02:33:45 UTC
+++ ../../src-qt5/OS-detect.pri
@@ -39,6 +39,12 @@ isEmpty(OS){
     OS = DragonFly
     LIBS += -L/usr/local/lib -L/usr/lib
 
+  }else : midnightbsd-*{
+    isEmpty(PREFIX){ PREFIX=/usr/local }
+    OS = FreeBSD
+    LIBS += -L/usr/local/lib -L/usr/lib
+     #Use the defaults for everything else
+
   }else : freebsd-*{
     isEmpty(PREFIX){ PREFIX=/usr/local }
     OS = FreeBSD
