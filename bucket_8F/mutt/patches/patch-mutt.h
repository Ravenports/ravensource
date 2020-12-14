--- mutt.h.orig	2020-12-04 18:38:44 UTC
+++ mutt.h
@@ -169,6 +169,16 @@ typedef enum
   MUTT_WRITE_HEADER_MIME
 } mutt_write_header_mode;
 
+/* flags for SmartDate */
+typedef enum {
+    FUTURE      = 1,
+    SMARTTIME   = 2,
+    YESTERDAY   = 3,
+    WEEKDAY     = 4,
+    STANDARD    = 5,
+    ANCIENT     = 6
+} smartdate_type;
+
 /* types for mutt_add_hook() */
 #define MUTT_FOLDERHOOK  1
 #define MUTT_MBOXHOOK    (1<<1)
@@ -236,6 +246,7 @@ enum
   MUTT_EXPIRED,
   MUTT_SUPERSEDED,
   MUTT_TRASH,
+  MUTT_THREADCOMPLETE,
 
   /* actions for mutt_pattern_comp/mutt_pattern_exec */
   MUTT_AND,
@@ -421,6 +432,7 @@ enum
   OPTFCCCLEAR,
   OPTFLAGSAFE,
   OPTFOLLOWUPTO,
+  OPTFORCEBASE64,
   OPTFORCENAME,
   OPTFORWDECODE,
   OPTFORWQUOTE,
@@ -593,6 +605,7 @@ enum
   OPTSMIMEISDEFAULT,
   OPTSMIMESELFENCRYPT,
   OPTASKCERTLABEL,
+  OPTSMIMENOSENDER,
   OPTSDEFAULTDECRYPTKEY,
   OPTPGPIGNORESUB,
   OPTPGPCHECKEXIT,
