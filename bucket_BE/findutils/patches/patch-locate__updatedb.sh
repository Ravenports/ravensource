--- locate/updatedb.sh.orig	2015-12-28 21:10:23 UTC
+++ locate/updatedb.sh
@@ -295,7 +295,7 @@ cd "$changeto"
 if test -n "$SEARCHPATHS"; then
   if [ "$LOCALUSER" != "" ]; then
     # : A1
-    su $LOCALUSER `select_shell $LOCALUSER` -c \
+    su -m $LOCALUSER -c \
     "$find $SEARCHPATHS $FINDOPTIONS \
      \\( $prunefs_exp \
      -type d -regex '$PRUNEREGEX' \\) -prune -o $print_option"
@@ -311,7 +311,7 @@ if test -n "$NETPATHS"; then
 myuid=`getuid`
 if [ "$myuid" = 0 ]; then
     # : A3
-    su $NETUSER `select_shell $NETUSER` -c \
+    su -m $NETUSER -c \
      "$find $NETPATHS $FINDOPTIONS \\( -type d -regex '$PRUNEREGEX' -prune \\) -o $print_option" ||
     exit $?
   else
@@ -362,7 +362,7 @@ cd "$changeto"
 if test -n "$SEARCHPATHS"; then
   if [ "$LOCALUSER" != "" ]; then
     # : A5
-    su $LOCALUSER `select_shell $LOCALUSER` -c \
+    su -m $LOCALUSER -c \
     "$find $SEARCHPATHS $FINDOPTIONS \
      \( $prunefs_exp \
      -type d -regex '$PRUNEREGEX' \) -prune -o $print_option" || exit $?
@@ -378,7 +378,7 @@ if test -n "$NETPATHS"; then
   myuid=`getuid`
   if [ "$myuid" = 0 ]; then
     # : A7
-    su $NETUSER `select_shell $NETUSER` -c \
+    su -m $NETUSER -c \
      "$find $NETPATHS $FINDOPTIONS \\( -type d -regex '$PRUNEREGEX' -prune \\) -o $print_option" ||
     exit $?
   else
