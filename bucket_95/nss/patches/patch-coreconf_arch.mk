--- coreconf/arch.mk.orig	2023-03-09 18:38:30 UTC
+++ coreconf/arch.mk
@@ -97,6 +97,10 @@ ifeq ($(OS_ARCH),Linux)
     include $(CORE_DEPTH)/coreconf/Linux.mk
 endif
 
+ifeq ($(OS_ARCH),DragonFly)
+OS_RELEASE := @OS_RELEASE@
+endif
+
 # Since all uses of OS_ARCH that follow affect only userland, we can
 # merge other Glibc systems with Linux here.
 ifeq ($(OS_ARCH),GNU)
