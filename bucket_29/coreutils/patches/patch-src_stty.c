--- src/stty.c.orig	2025-09-17 19:34:58 UTC
+++ src/stty.c
@@ -287,10 +287,10 @@ static struct mode_info const mode_info[
 # ifdef TAB3
   {"tab3", output, SANE_UNSET, TAB3, TABDLY},
 # endif
-# ifdef TAB2
+# if 0
   {"tab2", output, SANE_UNSET, TAB2, TABDLY},
 # endif
-# ifdef TAB1
+# if 0
   {"tab1", output, SANE_UNSET, TAB1, TABDLY},
 # endif
 # ifdef TAB0
