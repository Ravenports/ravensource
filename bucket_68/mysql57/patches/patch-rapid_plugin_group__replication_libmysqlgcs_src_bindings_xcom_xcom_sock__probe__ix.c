--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/sock_probe_ix.c.orig	2022-08-30 03:50:14 UTC
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/sock_probe_ix.c
@@ -147,7 +147,11 @@ static int init_sock_probe(sock_probe *s
    interfaces. We are doing this, since the size of sockaddr differs on
    some platforms.
    */
+#if defined(__NetBSD__)
+  for (i= 0, ptr=(char*) s->ifc.ifc_buf, end= (char*)s->ifc.ifc_buf + s->ifc.ifc_len;
+#else
   for (i= 0, ptr= s->ifc.ifc_buf, end= s->ifc.ifc_buf + s->ifc.ifc_len;
+#endif
        ptr<end;
        i++)
   {
