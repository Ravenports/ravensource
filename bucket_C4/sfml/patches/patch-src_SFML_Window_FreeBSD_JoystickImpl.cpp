add NetBSD support

--- src/SFML/Window/FreeBSD/JoystickImpl.cpp.orig	2025-04-22 13:06:02 UTC
+++ src/SFML/Window/FreeBSD/JoystickImpl.cpp
@@ -55,6 +55,16 @@ namespace
 std::unordered_map<unsigned int, std::string> plugged;
 std::unordered_map<int, std::pair<int, int>>  hatValueMap;
 
+#if defined(__NetBSD__)
+int hid_get_report_id(int fd)
+{
+    int id;
+    if (ioctl(fd, USB_GET_REPORT_ID, &id) < 0)
+       return -1;
+    return id;
+}
+#endif
+
 bool isJoystick(const char* name)
 {
     int file = ::open(name, O_RDONLY | O_NONBLOCK);
