--- libsrc/threads/posix-signals.ads.orig	2017-05-16 10:40:58 UTC
+++ libsrc/threads/posix-signals.ads
@@ -36,7 +36,6 @@
 
 with Ada.Task_Identification,
      Ada.Finalization,
-     POSIX,
      POSIX.C,
      POSIX.Process_Identification,
      System,
