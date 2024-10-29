--- src/file_reader.cpp.orig	2024-06-22 12:19:38 UTC
+++ src/file_reader.cpp
@@ -143,7 +143,7 @@ class MMapException : std::exception {};
 char*
 mmapReadOnly(int fd, offset_type offset, size_type size)
 {
-#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__HAIKU__) || defined(__DragonFly__) || defined(__NetBSD__)
   const auto MAP_FLAGS = MAP_PRIVATE;
 #elif defined(__FreeBSD__)
   const auto MAP_FLAGS = MAP_PRIVATE|MAP_PREFAULT_READ;
