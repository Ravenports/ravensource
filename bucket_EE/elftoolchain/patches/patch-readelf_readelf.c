--- readelf/readelf.c.orig	2019-07-18 03:57:34 UTC
+++ readelf/readelf.c
@@ -210,6 +210,47 @@ struct mips_option {
 	const char *desc;
 };
 
+/*
+ * compatibility functions
+ */
+
+static size_t
+port_strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+
+static char *
+port_strsep(char **stringp, const char *delim)
+{
+	char *s;
+	const char *spanp;
+	int c, sc;
+	char *tok;
+
+	if ((s = *stringp) == NULL)
+		return (NULL);
+	for (tok = s;;) {
+		c = *s++;
+		spanp = delim;
+		do {
+			if ((sc = *spanp++) == c) {
+				if (c == 0)
+					s = NULL;
+				else
+					s[-1] = 0;
+				*stringp = s;
+				return (tok);
+			}
+		} while (sc != 0);
+	}
+	/* NOTREACHED */
+}
+
 static void add_dumpop(struct readelf *re, size_t si, const char *sn, int op,
     int t);
 static const char *aeabi_adv_simd_arch(uint64_t simd);
@@ -3857,7 +3898,7 @@ dump_notes_content(struct readelf *re, c
 			name = "";
 		else if (note->n_namesz == 4 && strncmp(name, "CORE", 4) == 0)
 			name = "CORE";
-		else if (strnlen(name, note->n_namesz) >= note->n_namesz)
+		else if (port_strnlen(name, note->n_namesz) >= note->n_namesz)
 			name = "<invalid>";
 		printf("  %-13s %#010jx", name, (uintmax_t) note->n_descsz);
 		printf("      %s\n", note_type(name, re->ehdr.e_type,
@@ -7340,7 +7381,7 @@ parse_dwarf_op_long(struct readelf *re,
 		err(EXIT_FAILURE, "strdup failed");
 	bp = p;
 
-	while ((token = strsep(&p, ",")) != NULL) {
+	while ((token = port_strsep(&p, ",")) != NULL) {
 		for (i = 0; dwarf_op[i].ln != NULL; i++) {
 			if (!strcmp(token, dwarf_op[i].ln)) {
 				re->dop |= dwarf_op[i].value;
