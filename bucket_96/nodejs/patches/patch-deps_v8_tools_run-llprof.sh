--- deps/v8/tools/run-llprof.sh.orig	2021-11-09 13:29:21 UTC
+++ deps/v8/tools/run-llprof.sh
@@ -46,7 +46,7 @@ framework, then calls the low level tick
 EOF
 }
 
-if [ $# -eq 0 ] || [ "$1" == "-h" ]  || [ "$1" == "--help" ] ; then
+if [ $# -eq 0 ] || [ "$1" = "-h" ]  || [ "$1" = "--help" ] ; then
   usage
   exit 1
 fi
