--- hints/linux.sh.orig	2025-03-30 10:34:50 UTC
+++ hints/linux.sh
@@ -150,6 +150,10 @@ case "$optimize" in
     ;;
 esac
 
+lddlflags="-shared "
+ldflags="-Wl,-E "
+cccdlflags='-DPIC -fPIC'
+
 # Ubuntu 11.04 (and later, presumably) doesn't keep most libraries
 # (such as -lm) in /lib or /usr/lib.  So we have to ask gcc to tell us
 # where to look.  We don't want gcc's own libraries, however, so we
