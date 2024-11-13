$NetBSD: patch-src_SFML_Window_JoystickImpl.hpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- src/SFML/Window/JoystickImpl.hpp.orig	2024-11-09 21:00:47 UTC
+++ src/SFML/Window/JoystickImpl.hpp
@@ -85,7 +85,7 @@ struct JoystickState
 
     #include <SFML/Window/Unix/JoystickImpl.hpp>
 
-#elif defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_FREEBSD) || defined (SFML_SYSTEM_NETBSD)
 
     #include <SFML/Window/FreeBSD/JoystickImpl.hpp>
 
