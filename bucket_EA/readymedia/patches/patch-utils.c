avoid mkdir /, from freebsd ports

--- utils.c.orig	2023-05-31 08:25:59 UTC
+++ utils.c
@@ -287,7 +287,9 @@ make_dir(char * path, mode_t mode)
 			++s;
 		}
 
-		if (mkdir(path, mode) < 0) {
+		if (!(path[0] == '/' && s == path + 1) /* skip "/" */
+		    && mkdir(path, mode) < 0) {
+			int e = errno;
 			/* If we failed for any other reason than the directory
 			 * already exists, output a diagnostic and return -1.*/
 			if ((errno != EEXIST && errno != EISDIR)
