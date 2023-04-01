--- Makefile.PL.orig	2016-10-14 00:11:59 UTC
+++ Makefile.PL
@@ -26,6 +26,10 @@ for ($^O) {
   } elsif (/solaris/) {
     copy ('arch/solaris.xs', 'MemInfo.xs');
     print "Sys::MemInfo for Solaris\n";
+  } elsif (/midnight/) {
+    copy ('arch/freebsd.xs', 'MemInfo.xs');
+    $define = '-DFREEBSD5';
+    print "Sys::MemInfo for MidnightBSD\n";
   } elsif (/freebsd/) {
     copy ('arch/freebsd.xs', 'MemInfo.xs');
     $kver = `uname -r`;
@@ -36,6 +40,9 @@ for ($^O) {
     } else {
       print "Sys::MemInfo for FreeBSD 4 and lower\n";
     }
+  } elsif (/dragonfly/) {
+    copy ('arch/dragonfly.xs', 'MemInfo.xs');
+    print "Sys::MemInfo for DragonFly\n";
   } elsif (/bsd/) {
     copy ('arch/bsd.xs', 'MemInfo.xs');
     if (/netbsd/) {
