--- src/fs_unix.cpp.orig	2024-06-22 12:19:38 UTC
+++ src/fs_unix.cpp
@@ -36,7 +36,7 @@ namespace unix {
 
 zsize_t FD::readAt(char* dest, zsize_t size, offset_t offset) const
 {
-#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__HAIKU__) || defined(__DragonFly__)
 # define PREAD pread
 #else
 # define PREAD pread64
