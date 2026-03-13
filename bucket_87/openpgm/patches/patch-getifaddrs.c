--- getifaddrs.c.orig	2020-08-31 03:14:09 UTC
+++ getifaddrs.c
@@ -325,7 +325,7 @@ again:
 }
 #endif /* SIOCGLIFCONF */
 
-#ifdef SIOCGIFCONF
+#if defined SIOCGIFCONF && !defined(__sun)
 /* Popular socket option for enumerating interfaces.  However returned
  * structure is often harded coded for IPv4 addressing and so either
  * an alternative or additional API is required for IPv6 support.
