--- coreconf/arch.mk.orig	2020-10-16 14:50:49 UTC
+++ coreconf/arch.mk
@@ -26,7 +26,7 @@ OS_ARCH := $(subst /,_,$(shell uname -s)
 # Attempt to differentiate between sparc and x86 Solaris
 #
 
-OS_TEST := $(shell uname -m)
+OS_TEST := $(shell uname -p)
 ifeq ($(OS_TEST),i86pc)
     OS_RELEASE := $(shell uname -r)_$(OS_TEST)
 else
@@ -119,6 +119,10 @@ ifeq ($(OS_ARCH),Linux)
     include $(CORE_DEPTH)/coreconf/Linux.mk
 endif
 
+ifeq ($(OS_ARCH),DragonFly)
+OS_RELEASE := @OS_RELEASE@
+endif
+
 # Since all uses of OS_ARCH that follow affect only userland, we can
 # merge other Glibc systems with Linux here.
 ifeq ($(OS_ARCH),GNU)
