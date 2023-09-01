--- screen.c.orig	2023-08-16 00:29:26 UTC
+++ screen.c
@@ -2234,7 +2234,7 @@ static char *pad_expand(char *buf, char
   pn2 = pn = p + padlen;
   r = winmsg_numrend;
   while (p >= buf) {
-    if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1]) {
+    if (r && p - buf == winmsg_rendpos[r - 1]) {
       winmsg_rendpos[--r] = pn - buf;
       continue;
     }
