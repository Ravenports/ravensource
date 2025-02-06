--- coreconf/Darwin.mk.orig	2025-01-31 11:17:15 UTC
+++ coreconf/Darwin.mk
@@ -7,8 +7,8 @@ CC     ?= gcc
 CCC    ?= g++
 RANLIB ?= ranlib
 
+NSS_ENABLE_WERROR = 0
 include $(CORE_DEPTH)/coreconf/UNIX.mk
-include $(CORE_DEPTH)/coreconf/Werror.mk
 
 DEFAULT_COMPILER = gcc
 
@@ -127,21 +127,4 @@ PROCESS_MAP_FILE = grep -v ';+' $< | gre
 USE_SYSTEM_ZLIB = 1
 ZLIB_LIBS	= -lz
 
-# The system sqlite library in the latest version of Mac OS X often becomes
-# newer than the sqlite library in NSS. This may result in certain Mac OS X
-# system libraries having unresolved sqlite symbols during the shlibsign step
-# of the NSS build when we set DYLD_LIBRARY_PATH to the NSS lib directory and
-# the NSS libsqlite3.dylib is used instead of the system one. So just use the
-# system sqlite library on Mac, if it's sufficiently new.
-
-SYS_SQLITE3_VERSION_FULL := $(shell /usr/bin/sqlite3 -version | awk '{print $$1}')
-SYS_SQLITE3_VERSION_MAJOR := $(shell echo $(SYS_SQLITE3_VERSION_FULL) | awk -F. '{ print $$1 }')
-SYS_SQLITE3_VERSION_MINOR := $(shell echo $(SYS_SQLITE3_VERSION_FULL) | awk -F. '{ print $$2 }')
-
-ifeq (3,$(SYS_SQLITE3_VERSION_MAJOR))
-    ifeq (,$(filter-out 0 1 2 3 4,$(SYS_SQLITE3_VERSION_MINOR)))
-        # sqlite <= 3.4.x is too old, it doesn't provide sqlite3_file_control
-    else
-        NSS_USE_SYSTEM_SQLITE = 1
-    endif
-endif
+NSS_USE_SYSTEM_SQLITE = 1
