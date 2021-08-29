--- Makefile.PL.orig	2021-05-06 02:53:32 UTC
+++ Makefile.PL
@@ -232,7 +232,7 @@ sub search_termlib {
         return (search_lib('-lncurses') || search_lib('-ltermcap')
                 || search_lib('-ltinfo') || search_lib('-lcurses'));
     } else {
-        return (search_lib('-ltermcap') || search_lib('-ltinfo')
+        return (search_lib('-ltinfo')
                 || search_lib('-lncurses') || search_lib('-lcurses'));
     }
 }
