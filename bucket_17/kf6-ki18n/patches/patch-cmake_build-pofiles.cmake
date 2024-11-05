--- cmake/build-pofiles.cmake.orig	2024-10-04 15:07:17 UTC
+++ cmake/build-pofiles.cmake
@@ -41,7 +41,7 @@ foreach(pofile IN LISTS pofiles)
 
     list(APPEND commands COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} -o ${dest}/${name}.mo ${PO_DIR}/${pofile})
     math(EXPR i "${i}+1")
-    if(i EQUAL ${numberOfProcesses})
+    if(i EQUAL 1)
         _processCommands()
         set(i 0)
         set(commands)
