--- coreconf/config.mk.orig	2026-02-19 09:30:44 UTC
+++ coreconf/config.mk
@@ -31,7 +31,7 @@ endif
 #######################################################################
 
 TARGET_OSES = FreeBSD NetBSD OpenUNIX QNX Darwin OpenBSD \
-              AIX WINNT Linux Android
+              AIX WINNT Linux Android DragonFly MidnightBSD
 
 ifeq (,$(filter-out $(TARGET_OSES),$(OS_TARGET)))
 include $(CORE_DEPTH)/coreconf/$(OS_TARGET).mk
