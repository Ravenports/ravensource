--- src/util.c.orig	2026-11-18 15:36:33 UTC
+++ src/util.c
@@ -256,7 +256,7 @@ static void printevents(const EventSet_T
 /**
  * PAM conversation
  */
-#if (defined(SOLARIS) && ! defined(__illumos__)) || defined(AIX)
+#if 0
 static int PAMquery(int num_msg, struct pam_message **msg, struct pam_response **resp, void *appdata_ptr) {
 #else
 static int PAMquery(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr) {
