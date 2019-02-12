--- coreconf/SunOS5.mk.orig	2019-01-25 23:52:51 UTC
+++ coreconf/SunOS5.mk
@@ -14,14 +14,14 @@ ifeq ($(USE_64), 1)
   ifdef NS_USE_GCC
       ARCHFLAG=-m64
   else
-      ifeq ($(OS_TEST),i86pc)
+      ifeq ($(OS_TEST),x86_64)
         ARCHFLAG=-xarch=amd64
       else
         ARCHFLAG=-xarch=v9
       endif
   endif
 else
-  ifneq ($(OS_TEST),i86pc)
+  ifneq ($(OS_TEST),x86_64)
     ifdef NS_USE_GCC
       ARCHFLAG=-mcpu=v9
     else
@@ -33,9 +33,9 @@ endif
 DEFAULT_COMPILER = cc
 
 ifdef NS_USE_GCC
-	CC         = gcc
+	CC         ?= gcc
 	OS_CFLAGS += -Wall -Wno-format -Werror-implicit-function-declaration -Wno-switch
-	CCC        = g++
+	CCC        ?= g++
 	CCC       += -Wall -Wno-format
 	ASFLAGS	  += -x assembler-with-cpp
 	OS_CFLAGS += $(NOMD_OS_CFLAGS) $(ARCHFLAG)
@@ -67,7 +67,7 @@ RANLIB      = echo
 CPU_ARCH    = sparc
 OS_DEFINES += -DSVR4 -DSYSV -D__svr4 -D__svr4__ -DSOLARIS -D_REENTRANT
 
-ifeq ($(OS_TEST),i86pc)
+ifeq ($(OS_TEST),x86_64)
 ifeq ($(USE_64),1)
     CPU_ARCH		= x86_64
 else
@@ -109,15 +109,11 @@ endif
 	DSO_LDOPTS += -shared -h $(notdir $@)
 else
 ifeq ($(USE_64), 1)
-	ifeq ($(OS_TEST),i86pc)
-	    DSO_LDOPTS +=-xarch=amd64
-	else
-	    DSO_LDOPTS +=-xarch=v9
-	endif
+	DSO_LDOPTS += -m64
 endif
 	DSO_LDOPTS += -G -h $(notdir $@)
 endif
-DSO_LDOPTS += -z combreloc -z defs -z ignore
+# DSO_LDOPTS += -Wl,-z,origin
 
 # -KPIC generates position independent code for use in shared libraries.
 # (Similarly for -fPIC in case of gcc.)
@@ -129,16 +125,4 @@ endif
 
 NOSUCHFILE   = /solaris-rm-f-sucks
 
-ifeq ($(BUILD_SUN_PKG), 1)
-# The -R '$ORIGIN' linker option instructs this library to search for its
-# dependencies in the same directory where it resides.
-ifeq ($(USE_64), 1)
-RPATH = -R '$$ORIGIN:/usr/lib/mps/secv1/64:/usr/lib/mps/64'
-else
-RPATH = -R '$$ORIGIN:/usr/lib/mps/secv1:/usr/lib/mps'
-endif
-else
-RPATH = -R '$$ORIGIN'
-endif
-
-OS_LIBS += -lthread -lnsl -lsocket -lposix4 -ldl -lc
+RPATH = $(LDFLAGS) #-Wl,-rpath,$(PREFIX)/lib/nss
