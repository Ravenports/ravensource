--- src/platforms/wayland/shm.cpp.orig	2024-02-21 11:27:59 UTC
+++ src/platforms/wayland/shm.cpp
@@ -77,9 +77,10 @@ std::unique_ptr<ShmBuffer> Shm::createBu
     auto format = toWaylandFormat(image.format());
     const int stride = image.bytesPerLine();
     const int32_t byteCount = image.size().height() * stride;
+    int fd;
 
 #if defined HAVE_MEMFD
-    int fd = memfd_create("kwayland-shared", MFD_CLOEXEC | MFD_ALLOW_SEALING);
+    fd = memfd_create("kwayland-shared", MFD_CLOEXEC | MFD_ALLOW_SEALING);
     if (fd >= 0) {
         fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_SEAL);
     } else
