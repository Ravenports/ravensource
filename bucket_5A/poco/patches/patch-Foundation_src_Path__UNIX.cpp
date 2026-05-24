--- Foundation/src/Path_UNIX.cpp.orig	2026-04-16 18:15:35.000000000 -0000
+++ Foundation/src/Path_UNIX.cpp
@@ -75,7 +75,7 @@ std::string PathImpl::selfImpl()
 	if (n > 0 && n < PATH_MAX)
 		path = buf;
 #elif POCO_OS == POCO_OS_SOLARIS
-	char * execName = getexecname();
+	const char * execName = getexecname();
 	if (execName)
 		path = execName;
 	else
