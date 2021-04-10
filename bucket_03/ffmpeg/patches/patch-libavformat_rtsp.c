--- libavformat/rtsp.c.orig	2021-04-08 21:28:40 UTC
+++ libavformat/rtsp.c
@@ -1664,7 +1664,12 @@ int ff_rtsp_make_setup_request(AVFormatC
             }
             if (ttl > 0)
                 snprintf(optbuf, sizeof(optbuf), "?ttl=%d", ttl);
-            getnameinfo((struct sockaddr*) &addr, sizeof(addr),
+            getnameinfo((struct sockaddr*) &addr,
+#if HAVE_STRUCT_SOCKADDR_SA_LEN
+                        ((struct sockaddr*) &addr)->sa_len,
+#else
+                        sizeof(addr),
+#endif
                         namebuf, sizeof(namebuf), NULL, 0, NI_NUMERICHOST);
             ff_url_join(url, sizeof(url), "rtp", NULL, namebuf,
                         port, "%s", optbuf);
@@ -1898,8 +1903,13 @@ redirect:
         goto fail;
     }
     if (!getpeername(tcp_fd, (struct sockaddr*) &peer, &peer_len)) {
-        getnameinfo((struct sockaddr*) &peer, peer_len, host, sizeof(host),
-                    NULL, 0, NI_NUMERICHOST);
+        getnameinfo((struct sockaddr*) &peer,
+#if HAVE_STRUCT_SOCKADDR_SA_LEN
+                    ((struct sockaddr*) &peer)->sa_len,
+#else
+                    peer_len,
+#endif
+                    host, sizeof(host), NULL, 0, NI_NUMERICHOST);
     }
 
     /* request options supported by the server; this also detects server
@@ -2417,7 +2427,11 @@ static int sdp_read_header(AVFormatConte
             AVDictionary *opts = map_to_opts(rt);
 
             err = getnameinfo((struct sockaddr*) &rtsp_st->sdp_ip,
+#if HAVE_STRUCT_SOCKADDR_SA_LEN
+                              ((struct sockaddr*) &rtsp_st->sdp_ip)->sa_len,
+#else
                               sizeof(rtsp_st->sdp_ip),
+#endif
                               namebuf, sizeof(namebuf), NULL, 0, NI_NUMERICHOST);
             if (err) {
                 av_log(s, AV_LOG_ERROR, "getnameinfo: %s\n", gai_strerror(err));
