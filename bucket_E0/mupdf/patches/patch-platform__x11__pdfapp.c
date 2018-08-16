--- platform/x11/pdfapp.c.orig	2018-04-12 13:14:06 UTC
+++ platform/x11/pdfapp.c
@@ -1331,6 +1331,8 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	case 'j':
 		{
 			int h = fz_pixmap_height(app->ctx, app->image);
+                        if ( (app->pany + h) <= app->winh )
+                            goto pagedown;
 			if (h <= app->winh || app->pany <= app->winh - h)
 			{
 				panto = PAN_TO_TOP;
@@ -1347,6 +1349,8 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	case 'k':
 		{
 			int h = fz_pixmap_height(app->ctx, app->image);
+                        if (app->pany >= 0)
+                            goto pageup;
 			if (h <= app->winh || app->pany == 0)
 			{
 				panto = PAN_TO_BOTTOM;
@@ -1422,6 +1426,7 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	 */
 
 	case ',':
+        pageup:
 		panto = PAN_TO_BOTTOM;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -1430,6 +1435,7 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 		break;
 
 	case '.':
+        pagedown:
 		panto = PAN_TO_TOP;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
