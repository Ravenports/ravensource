--- screen.c.orig	2017-10-23 11:32:41 UTC
+++ screen.c
@@ -2214,7 +2214,7 @@ static char *pad_expand(char *buf, char
   pn2 = pn = p + padlen;
   r = winmsg_numrend;
   while (p >= buf) {
-    if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1]) {
+    if (r && p - buf == winmsg_rendpos[r - 1]) {
       winmsg_rendpos[--r] = pn - buf;
       continue;
     }
