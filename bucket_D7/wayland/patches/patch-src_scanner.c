--- src/scanner.c.orig	2018-08-24 18:04:36 UTC
+++ src/scanner.c
@@ -1951,7 +1951,7 @@ int main(int argc, char *argv[])
 		buf = XML_GetBuffer(ctx.parser, XML_BUFFER_SIZE);
 		len = fread(buf, 1, XML_BUFFER_SIZE, input);
 		if (len < 0) {
-			fprintf(stderr, "fread: %m\n");
+			fprintf(stderr, "fread: %s\n", strerror(errno));
 			fclose(input);
 			exit(EXIT_FAILURE);
 		}
