--- coreconf/ruleset.mk.orig	2019-01-23 08:35:38 UTC
+++ coreconf/ruleset.mk
@@ -53,7 +53,7 @@
 #
 
 ifndef COMPILER_TAG
-    ifneq ($(DEFAULT_COMPILER), $(notdir $(firstword $(CC))))
+    ifneq ($(DEFAULT_COMPILER), $(CC))
 #
 # Temporary define for the Client; to be removed when binary release is used
 #
