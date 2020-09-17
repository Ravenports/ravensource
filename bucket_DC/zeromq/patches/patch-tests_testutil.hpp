--- tests/testutil.hpp.orig	2020-09-07 16:01:31 UTC
+++ tests/testutil.hpp
@@ -46,6 +46,10 @@
 #include <unistd.h>
 #include <stdlib.h>
 #endif
+#if defined __DragonFly__ || defined __FreeBSD__
+#include <netinet/in.h>
+#include <sys/socket.h>
+#endif
 
 //  This defines the settle time used in tests; raise this if we
 //  get test failures on slower systems due to binds/connects not
