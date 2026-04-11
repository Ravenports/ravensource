--- src/util.c.orig	2025-05-08 07:51:11 UTC
+++ src/util.c
@@ -323,7 +323,7 @@ static void printevents(unsigned int eve
 /**
  * PAM conversation
  */
-#if defined(SOLARIS) || defined(AIX)
+#if 0
 static int PAMquery(int num_msg, struct pam_message **msg, struct pam_response **resp, void *appdata_ptr) {
 #else
 static int PAMquery(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr) {
