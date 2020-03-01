--- screen.c.orig	2020-02-05 20:09:38 UTC
+++ screen.c
@@ -2216,7 +2216,7 @@ static char *pad_expand(char *buf, char
   pn2 = pn = p + padlen;
   r = winmsg_numrend;
   while (p >= buf) {
-    if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1]) {
+    if (r && p - buf == winmsg_rendpos[r - 1]) {
       winmsg_rendpos[--r] = pn - buf;
       continue;
     }
