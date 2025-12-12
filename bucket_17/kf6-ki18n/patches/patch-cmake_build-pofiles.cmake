--- cmake/build-pofiles.cmake.orig	2025-12-05 13:21:38 UTC
+++ cmake/build-pofiles.cmake
@@ -41,7 +41,7 @@ foreach(pofile IN LISTS pofiles)
 
     list(APPEND commands COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} -o ${dest}/${name}.mo ${PO_DIR}/${pofile})
     math(EXPR i "${i}+1")
-    if(i EQUAL ${numberOfProcesses})
+    if(i EQUAL 1)
         _processCommands()
         set(i 0)
         set(commands)
