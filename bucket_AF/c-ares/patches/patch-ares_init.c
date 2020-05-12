Description: Add the ares_get_config() routine used by Unreal IRCd.
 Originally taken from the Unreal IRCd distribution, later modified
 by me to properly support IPv6 nameserver addresses since c-ares-1.7.1.
Origin: the Unreal IRCd distribution
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: no
Last-Update: 2010-12-19

--- ares.h.orig	2019-08-06 14:29:37 UTC
+++ ares.h
@@ -279,6 +279,14 @@ struct ares_options {
   char *resolvconf_path;
 };
 
+/** Public available config (readonly) interface for ares_get_config(). */
+struct ares_config_info {
+	int timeout;
+	int tries;
+	int numservers;
+	char **servers;
+};
+
 struct hostent;
 struct timeval;
 struct sockaddr;
@@ -722,6 +730,8 @@ CARES_EXTERN const char *ares_inet_ntop(
 CARES_EXTERN int ares_inet_pton(int af, const char *src, void *dst);
 
 
+CARES_EXTERN int ares_get_config(struct ares_config_info *d, ares_channel c);
+
 #ifdef  __cplusplus
 }
 #endif
--- ares_init.c.orig	2020-03-12 08:02:50 UTC
+++ ares_init.c
@@ -2462,6 +2462,36 @@ static int sortlist_alloc(struct apatter
   return 1;
 }
 
+int ares_get_config(struct ares_config_info *d, ares_channel c)
+{
+	int i;
+	const char *p;
+	char tmp[sizeof("ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255")];
+
+	memset(d, 0, sizeof(struct ares_config_info));
+
+	d->timeout = c->timeout;
+	d->tries = c->tries;
+	d->numservers = c->nservers;
+	d->servers = calloc(sizeof(char *), c->nservers);
+	for (i = 0; i < c->nservers; i++)
+	{
+		if (c->servers[i].addr.family == AF_INET)
+			p = ares_inet_ntop(c->servers[i].addr.family,
+			    (const char *)&c->servers[i].addr.addrV4,
+			    tmp, sizeof(tmp));
+		else if (c->servers[i].addr.family == AF_INET6)
+			p = ares_inet_ntop(c->servers[i].addr.family,
+			    (const char *)&c->servers[i].addr.addrV6,
+			    tmp, sizeof(tmp));
+		else
+			p = NULL;
+		d->servers[i] = p ? strdup(p) : NULL;
+	}
+
+	return ARES_SUCCESS;
+}
+
 /* initialize an rc4 key. If possible a cryptographically secure random key
    is generated using a suitable function (for example win32's RtlGenRandom as
    described in
