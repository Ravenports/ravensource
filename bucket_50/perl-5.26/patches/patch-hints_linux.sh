--- hints/linux.sh.bak	2016-07-14 19:07:40.000000000 +0000
+++ hints/linux.sh	2017-05-18 05:59:27.668407063 +0000
@@ -150,6 +150,10 @@
     ;;
 esac
 
+lddlflags="-shared "
+ldflags="-Wl,-E "
+cccdlflags='-DPIC -fPIC'
+
 # Ubuntu 11.04 (and later, presumably) doesn't keep most libraries
 # (such as -lm) in /lib or /usr/lib.  So we have to ask gcc to tell us
 # where to look.  We don't want gcc's own libraries, however, so we
