--- conversions.c.orig	2021-07-27 18:08:32 UTC
+++ conversions.c
@@ -1310,6 +1310,7 @@ void to_zval_read_in6_pktinfo(const char
 
 /* CONVERSIONS for struct ucred */
 #ifdef SO_PASSCRED
+#if !defined(__DragonFly__)
 static const field_descriptor descriptors_ucred[] = {
 		{"pid", sizeof("pid"), 1, offsetof(struct ucred, pid), from_zval_write_pid_t, to_zval_read_pid_t},
 		{"uid", sizeof("uid"), 1, offsetof(struct ucred, uid), from_zval_write_uid_t, to_zval_read_uid_t},
@@ -1317,6 +1318,15 @@ static const field_descriptor descriptor
 		{"gid", sizeof("gid"), 1, offsetof(struct ucred, gid), from_zval_write_uid_t, to_zval_read_uid_t},
 		{0}
 };
+#else
+static const field_descriptor descriptors_ucred[] = {
+		{"pid", sizeof("pid"), 1, offsetof(struct cmsgcred, cmcred_pid), from_zval_write_pid_t, to_zval_read_pid_t},
+		{"uid", sizeof("uid"), 1, offsetof(struct cmsgcred, cmcred_uid), from_zval_write_uid_t, to_zval_read_uid_t},
+		/* assume the type gid_t is the same as uid_t: */
+		{"gid", sizeof("gid"), 1, offsetof(struct cmsgcred, cmcred_gid), from_zval_write_uid_t, to_zval_read_uid_t},
+		{0}
+};
+#endif
 void from_zval_write_ucred(const zval *container, char *ucred_c, ser_context *ctx)
 {
 	from_zval_write_aggregation(container, ucred_c, descriptors_ucred, ctx);
