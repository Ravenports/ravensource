--- coreconf/command.mk.orig	2022-03-03 10:18:53 UTC
+++ coreconf/command.mk
@@ -12,7 +12,7 @@ AS            = $(CC)
 ASFLAGS      += $(CFLAGS)
 CCF           = $(CC) $(CFLAGS)
 LINK_DLL      = $(LD) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLDFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
+CFLAGS       += $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
                 $(DEFINES) $(INCLUDES) $(XCFLAGS)
 CSTD          = -std=c99
 CXXSTD        = -std=c++11
