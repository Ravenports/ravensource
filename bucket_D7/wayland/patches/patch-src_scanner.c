--- src/scanner.c.orig	2019-03-21 00:55:25 UTC
+++ src/scanner.c
@@ -1956,7 +1956,7 @@ int main(int argc, char *argv[])
 		buf = XML_GetBuffer(ctx.parser, XML_BUFFER_SIZE);
 		len = fread(buf, 1, XML_BUFFER_SIZE, input);
 		if (len < 0) {
-			fprintf(stderr, "fread: %m\n");
+			fprintf(stderr, "fread: %s\n", strerror(errno));
 			fclose(input);
 			exit(EXIT_FAILURE);
 		}
