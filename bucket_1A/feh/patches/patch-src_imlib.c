--- src/imlib.c.orig	2019-02-17 07:47:27 UTC
+++ src/imlib.c
@@ -457,7 +457,11 @@ static char *feh_magick_load_image(char
 	 * this function.
 	 */
 	if (getenv("MAGICK_TMPDIR") == NULL) {
+#ifdef __sun__
+		if ((mktemp(tempdir) == NULL) || (mkdir(tempdir, 0700) != 0)) {
+#else
 		if (mkdtemp(tempdir) == NULL) {
+#endif
 			weprintf("%s: ImageMagick may leave temporary files in /tmp. mkdtemp failed:", filename);
 		} else {
 			created_tempdir = 1;
