--- src/lua_sysctl.c.orig	2021-03-20 15:41:49.561385000 +0100
+++ src/lua_sysctl.c	2021-03-20 15:42:52.220425000 +0100
@@ -273,10 +273,12 @@
 	if ((kind & CTLTYPE) == CTLTYPE_NODE)
 		return (luaL_error(L, "oid '%s' isn't a leaf node", bufp));
 	if (!(kind & CTLFLAG_WR)) {
+#ifndef __DragonFly__
 		if (kind & CTLFLAG_TUN)
 			return (luaL_error(L, "oid '%s' is a read only tunable. "
 					"Tunable values are set in /boot/loader.conf", bufp));
 		else
+#endif
 			return (luaL_error(L, "oid '%s' is read only", bufp));
 	}
 
