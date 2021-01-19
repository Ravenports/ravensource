--- src/net/os/dragonfly/Link.inc.orig	2020-12-28 14:19:43 UTC
+++ src/net/os/dragonfly/Link.inc
@@ -32,7 +32,7 @@
  */
 
 
-static boolean_t _update(T L, const char *interface) {
+static bool _update(T L, const char *interface) {
         for (struct ifaddrs *a = _stats.addrs; a != NULL; a = a->ifa_next) {
                 if (a->ifa_addr == NULL)
                         continue;
