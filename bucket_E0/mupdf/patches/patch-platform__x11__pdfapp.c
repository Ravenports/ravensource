--- platform/x11/pdfapp.c.orig	2019-05-06 11:53:09 UTC
+++ platform/x11/pdfapp.c
@@ -1191,6 +1191,8 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	case 'j':
 		{
 			int h = fz_pixmap_height(app->ctx, app->image);
+                        if ( (app->pany + h) <= app->winh )
+                            goto pagedown;
 			if (h <= app->winh || app->pany <= app->winh - h)
 			{
 				panto = PAN_TO_TOP;
@@ -1207,6 +1209,8 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	case 'k':
 		{
 			int h = fz_pixmap_height(app->ctx, app->image);
+                        if (app->pany >= 0)
+                            goto pageup;
 			if (h <= app->winh || app->pany == 0)
 			{
 				panto = PAN_TO_BOTTOM;
@@ -1282,6 +1286,7 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	 */
 
 	case ',':
+        pageup:
 		panto = PAN_TO_BOTTOM;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -1290,6 +1295,7 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 		break;
 
 	case '.':
+        pagedown:
 		panto = PAN_TO_TOP;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
