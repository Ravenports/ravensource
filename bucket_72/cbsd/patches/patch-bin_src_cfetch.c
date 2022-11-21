--- bin/src/cfetch.c.orig	2022-11-06 18:48:13 UTC
+++ bin/src/cfetch.c
@@ -99,7 +99,7 @@ main(int argc, char *argv[])
 static int
 fetch_files(char *urls, char *fout)
 {
-	FILE *fetch_out;
+	FXRETTYPE fetch_out;
 	FILE *file_out;
 	struct url_stat ustat;
 	off_t total_bytes;
@@ -159,7 +159,7 @@ fetch_files(char *urls, char *fout)
 	}
 
 	current_bytes = 0;
-	while ((chunk = fread(block, 1, sizeof(block), fetch_out)) > 0) {
+	while ((chunk = es_fread(block, 1, sizeof(block), fetch_out)) > 0) {
 		if (fwrite(block, 1, chunk, file_out) < chunk) {
 			break;
 		}
@@ -182,7 +182,7 @@ fetch_files(char *urls, char *fout)
 	if (ustat.size > 0 && fsize < ustat.size) {
 		if (fetchLastErrCode == 0) {
 			// small chunk
-			fclose(fetch_out);
+			es_fclose(fetch_out);
 			fclose(file_out);
 			return 0;
 		}
@@ -190,7 +190,7 @@ fetch_files(char *urls, char *fout)
 		nsuccess++;
 	}
 
-	fclose(fetch_out);
+	es_fclose(fetch_out);
 	fclose(file_out);
 
 	gettimeofday(&now_time, NULL);
