--- coreconf/UNIX.mk.orig	2022-11-10 10:16:42 UTC
+++ coreconf/UNIX.mk
@@ -10,10 +10,8 @@ AR          = ar cr $@
 LDOPTS     += -L$(SOURCE_LIB_DIR)
 
 ifdef BUILD_OPT
-	OPTIMIZER  += -O
 	DEFINES    += -UDEBUG -DNDEBUG
 else
-	OPTIMIZER  += -g
 	DEFINES    += -DDEBUG -UNDEBUG
 endif
 
