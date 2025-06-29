--- solenv/gbuild/platform/DRAGONFLY_X86_64_GCC.mk.orig	2025-06-05 10:22:59 UTC
+++ solenv/gbuild/platform/DRAGONFLY_X86_64_GCC.mk
@@ -11,6 +11,6 @@
 
 include $(GBUILDDIR)/platform/unxgcc.mk
 
-gb_CppunitTest_CPPTESTPRECOMMAND := LD_LIBRARY_PATH=$(WORKDIR)/UnpackedTarball/cppunit/src/cppunit/.libs:/usr/pkg/lib
+gb_CppunitTest_CPPTESTPRECOMMAND := LD_LIBRARY_PATH=$(INSTDIR)/program
 
 # vim: set noet sw=4:
