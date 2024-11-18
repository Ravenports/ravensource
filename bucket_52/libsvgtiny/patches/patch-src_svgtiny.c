--- src/svgtiny.c.orig	2023-12-27 21:45:54 UTC
+++ src/svgtiny.c
@@ -586,7 +586,7 @@ struct svgtiny_diagram *svgtiny_create(v
 {
 	struct svgtiny_diagram *diagram;
 
-	diagram = calloc(sizeof(*diagram), 1);
+	diagram = calloc(1, sizeof(*diagram));
 	if (!diagram)
 		return 0;
 
