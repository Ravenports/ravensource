--- common/util.c.orig	2007-11-18 16:41:42 UTC
+++ common/util.c
@@ -163,7 +163,11 @@ enum nresult
 nget_uslong(SCR *sp, u_long *valp, const CHAR_T *p, CHAR_T **endp, int base)
 {
 	errno = 0;
+#if defined(__sun__) || defined(__linux__)
+	*valp = STRTOUL(p, (char **)endp, base);
+#else
 	*valp = STRTOUL(p, endp, base);
+#endif
 	if (errno == 0)
 		return (NUM_OK);
 	if (errno == ERANGE && *valp == ULONG_MAX)
@@ -181,7 +185,11 @@ enum nresult
 nget_slong(SCR *sp, long int *valp, const CHAR_T *p, CHAR_T **endp, int base)
 {
 	errno = 0;
+#if defined(__sun__) || defined(__linux__)
+	*valp = STRTOL(p, (char **)endp, base);
+#else
 	*valp = STRTOL(p, endp, base);
+#endif
 	if (errno == 0)
 		return (NUM_OK);
 	if (errno == ERANGE) {
