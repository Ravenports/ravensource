--- configure.sh.orig	2016-01-13 07:19:13 UTC
+++ configure.sh
@@ -108,6 +108,13 @@ then
       fi
       ;;
   esac
+else
+      if [ $debug = yes ]
+      then
+        CFLAGS="$CFLAGS -g"
+      else
+        CFLAGS="$CFLAGS -DNDEBUG"
+      fi
 fi
 
 if [ $rcode = yes ]
@@ -131,8 +138,7 @@ fi
 
 if [ $shared = yes ]
 then
-  TARGETS="$TARGETS libpicosat.so"
-  CFLAGS="$CFLAGS -fPIC"
+  TARGETS="$TARGETS libpicosat.so libpicosat_pic.a"
 fi
 echo "targets ... $TARGETS"
 
