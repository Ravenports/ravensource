$NetBSD: patch-env_env__sig.c,v 1.2 2014/07/23 00:22:42 ryoon Exp $

--- env/env_sig.c.orig	2010-04-12 20:25:33 UTC
+++ env/env_sig.c
@@ -4,6 +4,10 @@
  * $Id$
  */
 
+#if defined(_SCO_DS)
+typedef unsigned long long u_int64_t;
+#endif
+
 #include "db_config.h"
 
 #define	__INCLUDE_NETWORKING	1
