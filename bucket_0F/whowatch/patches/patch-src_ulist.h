--- src/ulist.h.orig	2018-04-11 06:10:50 UTC
+++ src/ulist.h
@@ -16,11 +16,11 @@
 struct user_t
 {
 	struct list_head head;
-	char 	name[UT_NAMESIZE + 1];
-	char 	tty[UT_LINESIZE + 1];
+	char 	name[sizeof(((struct utmpx *)0)->ut_user)];
+	char 	tty[sizeof(((struct utmpx *)0)->ut_line)];
 	int 	pid;
 	char 	parent[16];
-	char 	host[UT_HOSTSIZE + 1];
+	char 	host[sizeof(((struct utmpx *)0)->ut_host)];
 	int 	line;
 };
 
