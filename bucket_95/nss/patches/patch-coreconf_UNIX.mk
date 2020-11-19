--- coreconf/UNIX.mk.orig	2020-09-18 17:00:23 UTC
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
 
