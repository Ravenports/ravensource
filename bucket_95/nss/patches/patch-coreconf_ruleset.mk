--- coreconf/ruleset.mk.orig	2020-05-01 21:08:55 UTC
+++ coreconf/ruleset.mk
@@ -53,7 +53,7 @@
 #
 
 ifndef COMPILER_TAG
-    ifneq ($(DEFAULT_COMPILER), $(notdir $(firstword $(CC))))
+    ifneq ($(DEFAULT_COMPILER), $(CC))
 #
 # Temporary define for the Client; to be removed when binary release is used
 #
