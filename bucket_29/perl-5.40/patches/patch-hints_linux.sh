--- hints/linux.sh.orig	2024-08-26 15:16:21 UTC
+++ hints/linux.sh
@@ -176,6 +176,10 @@ case "$optimize" in
     ;;
 esac
 
+lddlflags="-shared "
+ldflags="-Wl,-E "
+cccdlflags='-DPIC -fPIC'
+
 # Ubuntu 11.04 (and later, presumably) doesn't keep most libraries
 # (such as -lm) in /lib or /usr/lib.  So we have to ask gcc to tell us
 # where to look.  We don't want gcc's own libraries, however, so we
