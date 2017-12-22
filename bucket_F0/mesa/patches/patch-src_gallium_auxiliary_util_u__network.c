--- src/gallium/auxiliary/util/u_network.c.orig	2017-12-21 17:31:21 UTC
+++ src/gallium/auxiliary/util/u_network.c
@@ -6,7 +6,7 @@
 #if defined(PIPE_SUBSYSTEM_WINDOWS_USER)
 #  include <winsock2.h>
 #  include <windows.h>
-#elif defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) || \
+#elif defined(PIPE_OS_LINUX) || defined(PIPE_OS_BSD) || defined(PIPE_OS_HAIKU) || \
    defined(PIPE_OS_APPLE) || defined(PIPE_OS_CYGWIN) || defined(PIPE_OS_SOLARIS)
 #  include <sys/socket.h>
 #  include <netinet/in.h>
