--- solenv/gbuild/platform/DRAGONFLY_X86_64_GCC.mk.orig	2024-09-23 13:53:35 UTC
+++ solenv/gbuild/platform/DRAGONFLY_X86_64_GCC.mk
@@ -11,6 +11,6 @@
 
 include $(GBUILDDIR)/platform/unxgcc.mk
 
-gb_CppunitTest_CPPTESTPRECOMMAND := LD_LIBRARY_PATH=$(WORKDIR)/UnpackedTarball/cppunit/src/cppunit/.libs:/usr/pkg/lib
+gb_CppunitTest_CPPTESTPRECOMMAND := LD_LIBRARY_PATH=$(INSTDIR)/program
 
 # vim: set noet sw=4:
