--- vcl/Executable_visualbackendtest.mk.orig	2017-05-03 16:46:29 UTC
+++ vcl/Executable_visualbackendtest.mk
@@ -41,8 +41,8 @@ $(eval $(call gb_Executable_use_static_libraries,visua
     vclmain \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD, $(OS)))
 $(eval $(call gb_Executable_add_libs,visualbackendtest,\
	-lm \
	-ldl \
