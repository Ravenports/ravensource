--- Foundation/src/Path_UNIX.cpp.orig	2025-05-12 09:00:11 UTC
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
