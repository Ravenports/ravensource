--- qtgui/qmkmk.sh.orig	2024-07-12 07:10:09 UTC
+++ qtgui/qmkmk.sh
@@ -2,6 +2,7 @@
 # This is used with meson for the recoll custom_target().
 # This just runs qmake then make
 # I could find no way to do this in 2 steps inside meson
+set -x
 set -e
 pro_file=$1
 shift
@@ -13,13 +14,6 @@ QMAKE=${QMAKE:-qmake}
 MAKE=${MAKE:-make}
 
 ncpus=2
-if test -x /usr/bin/nproc ; then
-    ncpus=`nproc`
-elif which sysctl > /dev/null ; then
-    ncpus=`sysctl hw.ncpu | awk '{print $3}'`
-elif test -f /proc/cpuinfo ; then
-    ncpus=`grep -E '^processor[        ]*:' /proc/cpuinfo | wc -l`
-fi
 
 cd $dir
 ${QMAKE} $fn $*
