--- run_acats.sh.orig	2024-08-01 17:06:01 UTC
+++ run_acats.sh
@@ -5,21 +5,6 @@ if [ "$testdir" = "" ]; then
    exit 1
 fi
 
-# Provide which replacement.
-#
-# type -p is missing from Solaris 2 /bin/sh and /bin/ksh (ksh88), but both
-# ksh93 and bash have it.
-# type output format differs between ksh88 and ksh93, so avoid it if
-# type -p is present.  Unfortunately, HP-UX /bin/sh ignores -p with type.
-# Fall back to whence which ksh88 and ksh93 provide, but bash does not.
-
-which () {
-    path=`type -p $* 2>/dev/null` && { echo $path | awk '{print $NF}'; return 0; }
-    path=`type $* 2>/dev/null` && { echo $path | awk '{print $NF}'; return 0; }
-    path=`whence $* 2>/dev/null` && { echo $path; return 0; }
-    return 1
-}
-
 # Set up environment to use the Ada compiler from the object tree
 
 host_gnatchop=`which gnatchop`
