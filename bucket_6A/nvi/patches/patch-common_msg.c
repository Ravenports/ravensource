Ignore LANG=C or any value of LANG.  It was causing exit messages of
"./C" file does not exist when LANG was defined in the environment.

--- common/msg.c.orig	2007-11-18 16:41:42 UTC
+++ common/msg.c
@@ -718,8 +718,7 @@ msg_open(SCR *sp, char *file)
 	char *p, *t, buf[MAXPATHLEN];
 
 	if ((p = strrchr(file, '/')) != NULL && p[1] == '\0' &&
-	    (((t = getenv("LC_MESSAGES")) != NULL && t[0] != '\0') ||
-	    ((t = getenv("LANG")) != NULL && t[0] != '\0'))) {
+	    (((t = getenv("LC_MESSAGES")) != NULL && t[0] != '\0'))) {
 		(void)snprintf(buf, sizeof(buf), "%s%s", file, t);
 		p = buf;
 	} else
