--- lig.awk.orig	2017-12-17 20:55:53.508219000 +0100
+++ lig.awk	2017-12-17 21:00:50.434299000 +0100
@@ -24,14 +24,20 @@
 c!=b { print c }
 
 /f[1-9]?$/ {
-	print gensub("f[1-9]?$", "ﬀ", "g", b);
-	if (c!=b) print gensub("f[1-9]?$", "ﬀ", "g", c);
+	out=b; gsub("f[1-9]?$", "ﬀ", out); print out
+	if (c!=b) {
+		out=c; gsub("f[1-9]?$", "ﬀ", out); print out
+	}
 
-	print gensub("f[1-9]?$", "ﬁ", "g", b);
-	if (c!=b) print gensub("f[1-9]?$", "ﬁ", "g", c);
+	out=b; gsub("f[1-9]?$", "ﬁ", out); print out
+	if (c!=b) {
+		out=c; gsub("f[1-9]?$", "ﬁ", out); print out
+	}
 
-	print gensub("f[1-9]?$", "ﬂ", "g", b);
-	if (c!=b) print gensub("f[1-9]?$", "ﬂ", "g", c);
+	out=b; gsub("f[1-9]?$", "ﬂ", out); print out
+	if (c!=b) {
+		out=c; gsub("f[1-9]?$", "ﬂ", out); print out
+	}
 }
 
 
