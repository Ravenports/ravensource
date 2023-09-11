--- dist/checkman.awk.orig	2022-09-12 14:35:36 UTC
+++ dist/checkman.awk
@@ -446,7 +446,7 @@ END {
 			gsub("\\(", " \\(", b)
 			gsub("\\)", "\\)", b)
 			split(tolower(i), a, "/")
-			print "egrep -in '^\\.IR.*" b "' $PLAN9/man/man*/* # Need " tolower(i) |"sort"
+			print "grep -E -in '^\\.IR.*" b "' $PLAN9/man/man*/* # Need " tolower(i) |"sort"
 		}
 	}
 	close("sort")
