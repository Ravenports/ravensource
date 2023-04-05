--- src/user-classify.c.orig	2019-04-23 15:16:09 UTC
+++ src/user-classify.c
@@ -41,6 +41,7 @@ static const char *default_excludes[] =
         "uucp",
         "nobody",
         "postgres",
+        "pgsql",
         "pvm",
         "rpm",
         "nfsnobody",
@@ -50,6 +51,7 @@ static const char *default_excludes[] =
         "games",
         "man",
         "at",
+        "saned",
         "gdm",
         "gnome-initial-setup"
 };
