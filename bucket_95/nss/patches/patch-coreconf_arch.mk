--- coreconf/arch.mk.orig	2025-06-19 13:14:58 UTC
+++ coreconf/arch.mk
@@ -63,6 +63,14 @@ ifeq ($(OS_ARCH),Linux)
     include $(CORE_DEPTH)/coreconf/Linux.mk
 endif
 
+ifeq ($(OS_ARCH),DragonFly)
+OS_RELEASE := @OS_RELEASE@
+endif
+
+ifeq ($(OS_ARCH),MidnightBSD)
+OS_RELEASE := @OS_RELEASE@
+endif
+
 # Since all uses of OS_ARCH that follow affect only userland, we can
 # merge other Glibc systems with Linux here.
 ifeq ($(OS_ARCH),GNU)
