From febfe49ca3ecab1a7142ecb34012c1f0b2bcdee8 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?C=C5=93ur?= <coeur@gmx.fr>
Date: Sat, 15 Jun 2024 07:24:06 +0800
Subject: [PATCH] bump miniupnpc to 2.2.8 (#6907)

* bump miniupnpc to 2.2.8

* Avoid build error "ln: include/miniupnpc/.: Operation not permitted"

partial patch

---
 Transmission.xcodeproj/project.pbxproj  | 2 +-
 libtransmission/port-forwarding-upnp.cc | 9 +++++++--
 third-party/miniupnp                    | 2 +-
 3 files changed, 9 insertions(+), 4 deletions(-)

--- libtransmission/port-forwarding-upnp.cc.orig
+++ libtransmission/port-forwarding-upnp.cc
@@ -261,8 +261,13 @@ tr_port_forwarding_state tr_upnpPulse(
 
         FreeUPNPUrls(&handle->urls);
         auto lanaddr = std::array<char, TR_ADDRSTRLEN>{};
-        if (UPNP_GetValidIGD(devlist, &handle->urls, &handle->data, std::data(lanaddr), std::size(lanaddr) - 1) ==
-            UPNP_IGD_VALID_CONNECTED)
+        if (
+#if (MINIUPNPC_API_VERSION >= 18)
+            UPNP_GetValidIGD(devlist, &handle->urls, &handle->data, std::data(lanaddr), std::size(lanaddr) - 1, nullptr, 0)
+#else
+            UPNP_GetValidIGD(devlist, &handle->urls, &handle->data, std::data(lanaddr), std::size(lanaddr) - 1)
+#endif
+            == UPNP_IGD_VALID_CONNECTED)
         {
             tr_logAddInfo(fmt::format(_("Found Internet Gateway Device '{url}'"), fmt::arg("url", handle->urls.controlURL)));
             tr_logAddInfo(fmt::format(_("Local Address is '{address}'"), fmt::arg("address", lanaddr.data())));
