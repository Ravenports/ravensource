--- qtgui/qmkmk.sh.orig	2024-11-24 13:43:48 UTC
+++ qtgui/qmkmk.sh
@@ -2,6 +2,7 @@
 # This is used with meson for the recoll custom_target().
 # This just runs qmake then make
 # I could find no way to do this in 2 steps inside meson
+set -x
 set -e
 pro_file=$1
 shift
@@ -13,16 +14,6 @@ QMAKE=${QMAKE:-qmake}
 MAKE=${MAKE:-make}
 
 ncpus=2
-if which nproc > /dev/null ; then
-    ncpus=`nproc`
-elif which sysctl > /dev/null ; then
-    ncpus=`sysctl hw.ncpu | awk '{print $2}'`
-elif test -f /proc/cpuinfo ; then
-    ncpus=`grep -E '^processor[        ]*:' /proc/cpuinfo | wc -l`
-fi
-if test -z "$ncpus" ; then
-    ncpus=1
-fi
 
 cd $dir
 ${QMAKE} $fn $*
