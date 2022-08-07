--- main.c.orig	2022-06-13 00:25:54 UTC
+++ main.c
@@ -1429,6 +1429,12 @@ main_Init(int argc, char **argv)
 		Global_Set(".MAKE.UID", buf);
 		snprintf(buf, sizeof buf, "%u", getgid());
 		Global_Set(".MAKE.GID", buf);
+		Global_Set(".MAKE.OS.NAME",          OSNAME);
+		Global_Set(".MAKE.OS.VERSION",       OSVERSION);
+		Global_Set(".MAKE.OS.RELEASE",       OSRELEASE);
+		Global_Set(".MAKE.OS.MAJOR",         OSMAJOR);
+		Global_Set(".MAKE.OS.ARCHITECTURE",  OSARCH);
+		Global_Set(".MAKE.OS.ARCH.STANDARD", STDARCH);
 	}
 	if (makelevel > 0) {
 		char pn[1024];
