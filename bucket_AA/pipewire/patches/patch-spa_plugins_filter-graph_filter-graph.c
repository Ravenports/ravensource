--- spa/plugins/filter-graph/filter-graph.c.orig	2025-04-14 09:46:02 UTC
+++ spa/plugins/filter-graph/filter-graph.c
@@ -299,7 +299,13 @@ static struct port *find_port(struct nod
 	const struct spa_fga_descriptor *d;
 	uint32_t i, n_ports, port_id = SPA_ID_INVALID;
 
-	str = strdupa(name);
+	str = ({
+		char *buf;
+		size_t len = strlen(name); 
+		buf = __builtin_alloca(len + 1);
+		buf[len] = '\0';
+		(char *)memcpy(buf, name, len);
+	});
 	col = strchr(str, ':');
 	if (col != NULL) {
 		struct node *find;
