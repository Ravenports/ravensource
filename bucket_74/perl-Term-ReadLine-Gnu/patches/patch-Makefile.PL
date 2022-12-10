--- Makefile.PL.orig	2022-11-26 16:52:12 UTC
+++ Makefile.PL
@@ -219,7 +219,7 @@ sub search_termlib {
         return (search_lib('-lncurses') || search_lib('-ltermcap')
                 || search_lib('-ltinfo') || '-lcurses');
     } else {
-        return (search_lib('-ltermcap') || search_lib('-ltinfo')
+        return (search_lib('-ltinfo')
                 || search_lib('-lncurses') || '-lcurses');
     }
 }
