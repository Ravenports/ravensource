--- coreconf/ruleset.mk.orig	2020-10-16 14:50:49 UTC
+++ coreconf/ruleset.mk
@@ -30,7 +30,7 @@
 #
 
 ifndef COMPILER_TAG
-    ifneq ($(DEFAULT_COMPILER), $(notdir $(firstword $(CC))))
+    ifneq ($(DEFAULT_COMPILER), $(CC))
 #
 # Temporary define for the Client; to be removed when binary release is used
 #
