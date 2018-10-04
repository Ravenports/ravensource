--- platform/x11/pdfapp.c.orig	2018-10-03 11:29:14 UTC
+++ platform/x11/pdfapp.c
@@ -1310,6 +1310,8 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	case 'j':
 		{
 			int h = fz_pixmap_height(app->ctx, app->image);
+                        if ( (app->pany + h) <= app->winh )
+                            goto pagedown;
 			if (h <= app->winh || app->pany <= app->winh - h)
 			{
 				panto = PAN_TO_TOP;
@@ -1326,6 +1328,8 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	case 'k':
 		{
 			int h = fz_pixmap_height(app->ctx, app->image);
+                        if (app->pany >= 0)
+                            goto pageup;
 			if (h <= app->winh || app->pany == 0)
 			{
 				panto = PAN_TO_BOTTOM;
@@ -1401,6 +1405,7 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 	 */
 
 	case ',':
+        pageup:
 		panto = PAN_TO_BOTTOM;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -1409,6 +1414,7 @@ void pdfapp_onkey(pdfapp_t *app, int c,
 		break;
 
 	case '.':
+        pagedown:
 		panto = PAN_TO_TOP;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
