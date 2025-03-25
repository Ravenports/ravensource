--- src/osdef.sh.orig	2025-03-24 19:38:42 UTC
+++ src/osdef.sh
@@ -35,6 +35,7 @@ cat << EOF > osdef0.c
 #include "os_unixx.h"	/* bring in header files for os_unix.c */
 
 #ifdef HAVE_TERMCAP_H
+# include <term.h>
 # include <termcap.h>	/* only for term.c */
 #endif
 
@@ -52,7 +53,7 @@ cat << EOF > osdef0.c
 #endif
 EOF
 
-$CC -I. -I$srcdir -E osdef0.c >osdef0.cc
+$CC -I. -I$srcdir -I/raven/include/ncurses -E osdef0.c >osdef0.cc
 
 # insert a space in front of each line, so that a function name at the
 # start of the line is matched with "[)*, 	]\1[ 	(]"
