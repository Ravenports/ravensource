--- app.cpp.orig	2023-03-18 13:30:06 UTC
+++ app.cpp
@@ -18,6 +18,7 @@
 #include <pwd.h>			// for getpwnam etc.
 #include <fcntl.h>
 #include <stdint.h>
+#include <paths.h>			// for _PATH_MAILDIR
 #include <cstring>
 #include <cstdio>
 #include <iostream>
@@ -716,7 +717,7 @@ void App::Login()
 			ck.open_session(DisplayName, pw->pw_uid);
 		}
 		catch(Ck::Exception &e) {
-			logStream << APPNAME << ": " << e << endl;
+			logStream << APPNAME << ": " << e.errstr << endl;
 			exit(ERR_EXIT);
 		}
 	}
@@ -834,7 +835,7 @@ void App::Login()
 			ck.close_session();
 		}
 		catch(Ck::Exception &e) {
-			logStream << APPNAME << ": " << e << endl;
+			logStream << APPNAME << ": " << e.errstr << endl;
 		}
 	}
 #endif
