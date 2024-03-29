--- src/evloop-default.c.orig	2023-09-04 12:50:34 UTC
+++ src/evloop-default.c
@@ -123,8 +123,10 @@ static void evloop_destroy(void *data)
     free(evdata->pollfds);
   if(evdata->pollwatches)
     free(evdata->pollwatches);
+#if HAVE_PPOLL
   if(evdata->signums)
     free(evdata->signums);
+#endif
 
   if(signal_observer == evdata)
     signal_observer = NULL;
