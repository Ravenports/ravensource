add NetBSD support

--- include/SFML/Config.hpp.orig	2024-12-20 23:55:10 UTC
+++ include/SFML/Config.hpp
@@ -86,6 +86,11 @@
 // FreeBSD
 #define SFML_SYSTEM_FREEBSD
 
+#elif defined(__NetBSD__)
+
+// NetBSD
+#define SFML_SYSTEM_NETBSD
+
 #elif defined(__OpenBSD__)
 
 // OpenBSD
