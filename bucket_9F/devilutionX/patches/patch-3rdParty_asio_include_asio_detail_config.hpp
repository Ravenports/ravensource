--- 3rdParty/asio/include/asio/detail/config.hpp.orig	2019-10-09 22:34:02 UTC
+++ 3rdParty/asio/include/asio/detail/config.hpp
@@ -1002,6 +1002,7 @@
    || (defined(__MACH__) && defined(__APPLE__)) \
    || defined(__FreeBSD__) \
    || defined(__NetBSD__) \
+   || defined(__DragonFly__) \
    || defined(__OpenBSD__) \
    || defined(__linux__) \
    || defined(__HAIKU__)
@@ -1043,6 +1044,7 @@
 #if (defined(__MACH__) && defined(__APPLE__)) \
   || defined(__FreeBSD__) \
   || defined(__NetBSD__) \
+  || defined(__DragonFly__) \
   || defined(__OpenBSD__)
 # if !defined(ASIO_HAS_KQUEUE)
 #  if !defined(ASIO_DISABLE_KQUEUE)
