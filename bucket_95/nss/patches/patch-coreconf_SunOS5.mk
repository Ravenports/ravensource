--- coreconf/SunOS5.mk.orig	2025-01-31 11:17:15 UTC
+++ coreconf/SunOS5.mk
@@ -33,10 +33,10 @@ endif
 DEFAULT_COMPILER = cc
 
 ifdef NS_USE_GCC
-	CC         = gcc
+	CC        ?= gcc
 	OS_CFLAGS += -Wall -Wno-format -Werror-implicit-function-declaration -Wno-switch
 	OS_CFLAGS += -D__EXTENSIONS__
-	CCC        = g++
+	CCC       ?= g++
 	CCC       += -Wall -Wno-format
 	ASFLAGS	  += -x assembler-with-cpp
 	OS_CFLAGS += $(NOMD_OS_CFLAGS) $(ARCHFLAG)
@@ -107,15 +107,11 @@ endif
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
@@ -127,16 +123,5 @@ endif
 
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
+OS_LIBS += -lrt
+RPATH = $(LDFLAGS) #-Wl,-rpath,$(PREFIX)/lib/nss
