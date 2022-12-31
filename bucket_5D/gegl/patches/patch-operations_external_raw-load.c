--- operations/external/raw-load.c.orig	2022-11-13 14:56:59 UTC
+++ operations/external/raw-load.c
@@ -114,7 +114,7 @@ prepare (GeglOperation *operation)
         g_warning ("raw-load: Error Initializing raw library");
       else
         {
-          p->LibRaw->params.shot_select = o->image_num;
+          p->LibRaw->rawparams.shot_select = o->image_num;
     
           p->LibRaw->params.aber[0] = 1.0;
           p->LibRaw->params.aber[2] = 1.0;
