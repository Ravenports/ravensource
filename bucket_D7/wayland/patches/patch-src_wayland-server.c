--- src/wayland-server.c.orig	2023-04-04 07:58:31 UTC
+++ src/wayland-server.c
@@ -40,7 +40,6 @@
 #include <assert.h>
 #include <sys/time.h>
 #include <fcntl.h>
-#include <sys/eventfd.h>
 #include <sys/file.h>
 #include <sys/stat.h>
 
@@ -1117,10 +1116,6 @@ wl_display_create(void)
 		return NULL;
 	}
 
-	display->terminate_efd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK);
-	if (display->terminate_efd < 0)
-		goto err_eventfd;
-
 	display->term_source = wl_event_loop_add_fd(display->loop,
 						    display->terminate_efd,
 						    WL_EVENT_READABLE,
@@ -1151,10 +1146,6 @@ wl_display_create(void)
 
 err_term_source:
 	close(display->terminate_efd);
-err_eventfd:
-	wl_event_loop_destroy(display->loop);
-	free(display);
-	return NULL;
 }
 
 static void
