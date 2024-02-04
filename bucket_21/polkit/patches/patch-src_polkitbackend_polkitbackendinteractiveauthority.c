* for *BSD netgroup functions

--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2024-01-17 15:43:53 UTC
+++ src/polkitbackend/polkitbackendinteractiveauthority.c
@@ -26,8 +26,13 @@
 #ifdef HAVE_NETGROUP_H
 #include <netgroup.h>
 #else
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#define BSD_NETGROUP
+#else
 #include <netdb.h>
 #endif
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
@@ -2257,7 +2262,7 @@ get_users_in_net_group (PolkitIdentity
 #ifdef HAVE_SETNETGRENT
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
-# ifdef HAVE_SETNETGRENT_RETURN
+# if defined(HAVE_SETNETGRENT_RETURN) && !defined(__NetBSD__)
   if (setnetgrent (name) == 0)
     {
       g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
