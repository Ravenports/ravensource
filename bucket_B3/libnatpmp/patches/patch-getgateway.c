From 39ad4b34b9674b115ac80c649458bc4af2e5ecb6 Mon Sep 17 00:00:00 2001
From: Ka Ho Ng <khng@FreeBSD.org>
Date: Mon, 10 Jan 2022 20:19:37 -0500
Subject: [PATCH] Set sa_len properly in getdefaultgateway()

In USE_SOCKET_ROUTE's implementation, sa_len of the sockaddrs need to be
set as well.

Sponsored by:	The FreeBSD Foundation
---
 getgateway.c | 2 ++
 1 file changed, 2 insertions(+)

--- getgateway.c.orig
+++ getgateway.c
@@ -270,7 +270,9 @@ int getdefaultgateway(in_addr_t *addr)
   rtm.rtm_addrs = rtm_addrs;
 
   so_dst.sa_family = AF_INET;
+  so_dst.sa_len = sizeof(struct sockaddr);
   so_mask.sa_family = AF_INET;
+  so_mask.sa_len = sizeof(struct sockaddr);
 
   NEXTADDR(RTA_DST, so_dst);
   NEXTADDR(RTA_NETMASK, so_mask);
