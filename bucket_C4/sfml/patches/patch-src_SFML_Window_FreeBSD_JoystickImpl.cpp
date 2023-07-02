$NetBSD: patch-src_SFML_Window_FreeBSD_JoystickImpl.cpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- src/SFML/Window/FreeBSD/JoystickImpl.cpp.orig	2023-06-20 21:44:57 UTC
+++ src/SFML/Window/FreeBSD/JoystickImpl.cpp
@@ -52,6 +52,16 @@ namespace
     std::map<unsigned int, std::string> plugged;
     std::map<int, std::pair<int, int> > hatValueMap;
 
+#if defined(__NetBSD__)
+    int hid_get_report_id(int fd)
+    {
+        int id;
+        if (ioctl(fd, USB_GET_REPORT_ID, &id) < 0)
+            return -1; 
+        return id;
+    }
+#endif
+
     bool isJoystick(const char *name)
     {
         int file = ::open(name, O_RDONLY | O_NONBLOCK);
