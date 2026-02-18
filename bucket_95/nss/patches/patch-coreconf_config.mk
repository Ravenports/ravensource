--- coreconf/config.mk.orig	2026-01-08 11:14:43 UTC
+++ coreconf/config.mk
@@ -31,7 +31,7 @@ endif
 #######################################################################
 
 TARGET_OSES = FreeBSD NetBSD OpenUNIX QNX Darwin OpenBSD \
-              AIX WINNT Linux Android
+              AIX WINNT Linux Android DragonFly MidnightBSD
 
 ifeq (,$(filter-out $(TARGET_OSES),$(OS_TARGET)))
 include $(CORE_DEPTH)/coreconf/$(OS_TARGET).mk
