--- run_all.sh.orig	2024-08-01 17:06:01 UTC
+++ run_all.sh
@@ -72,6 +72,14 @@ log () {
   echo "$@" >> $dir/acats.log
 }
 
+inform () {
+  printf "%04d    %7s" $1 $2
+}
+
+disinform () {
+  printf "\r"
+}
+
 dir=`${PWDCMD-pwd}`
 
 if [ "$dir" = "$testdir" ]; then
@@ -170,6 +178,7 @@ handle_fail () {
     glob_countxf=$as_val
   else
     # should have passed
+    disinform
     display "FAIL:	$1"
     as_fn_arith $glob_countf + 1
     glob_countf=$as_val
@@ -342,16 +351,7 @@ display `type gnatmake`
 gnatls -v >> $dir/acats.log
 display ""
 
-if [ -n "$GCC_RUNTEST_PARALLELIZE_DIR" ]; then
-  dir_support=$dir/../acats/support
-
-  rm -rf $dir/run
-  mv $dir/tests $dir/tests.$$ 2> /dev/null
-  rm -rf $dir/tests.$$ &
-  mkdir -p $dir/run
-
-  cp -pr $dir/../acats/tests $dir/
-else
+if true; then
   dir_support=$dir/support
 
   # Only build support if needed
@@ -509,10 +509,20 @@ glob_countxf=0
 # number of unexpected passes
 glob_countxp=0
 
-# These for possible parallel execution, see below
-par_count=0
-par_countm=0
-par_last=
+# Decrement after each test is processed
+countdown=0
+
+for chapter in $chapters; do
+   if [ -d $dir/tests/$chapter ]; then
+      cd $dir/tests/$chapter
+      ls *.a *.ada *.adt *.am *.au *.dep 2> /dev/null | \
+          sed -e 's/\(.*\)\..*/\1/g' | \
+          cut -c1-7 | sort | uniq \
+          > $dir/tests/$chapter/${chapter}.lst
+      countn=$(wc -l < $dir/tests/$chapter/${chapter}.lst)
+      countdown=$(expr $countdown + $countn) 
+   fi
+done
 
 for chapter in $chapters; do
    # Used to generate support once and finish after that.
@@ -526,43 +536,12 @@ for chapter in $chapters; do
       continue
    fi
 
-   cd $dir/tests/$chapter
-   ls *.a *.ada *.adt *.am *.au *.dep 2> /dev/null | \
-       sed -e 's/\(.*\)\..*/\1/g' | \
-       cut -c1-7 | sort | uniq \
-       > $dir/tests/$chapter/${chapter}.lst
-
    for i in `cat $dir/tests/$chapter/${chapter}.lst`; do
 
-      # If running multiple run_all.sh jobs in parallel, decide
-      # if we should run this test in the current instance.
-      if [ -n "$GCC_RUNTEST_PARALLELIZE_DIR" ]; then
-	 case "$i" in
-	    # Ugh, some tests have inter-test dependencies, those
-	    # tests have to be scheduled on the same parallel instance
-	    # as previous test.
-	    ce2108f | ce2108h | ce3112d) ;;
-	    # All others can be hopefully scheduled freely.
-	    *)
-	       as_fn_arith $par_countm + 1
-	       par_countm=$as_val
-	       [ $par_countm -eq 10 ] && par_countm=0
-	       if [ $par_countm -eq 1 ]; then
-		  as_fn_arith $par_count + 1
-		  par_count=$as_val
-		  if mkdir $GCC_RUNTEST_PARALLELIZE_DIR/$par_count 2>/dev/null; then
-		     par_last=1
-		  else
-		     par_last=
-		  fi
-	       fi;;
-	 esac
-	 if [ -z "$par_last" ]; then
-	    continue
-	 fi
-      fi
-
+      inform $countdown $i	
+      countdown=$(expr $countdown - 1)
       run_one_test $i
+      disinform
 
    done
 done
