--- src/event/modules/ngx_eventport_module.c.orig	2019-04-09 13:00:30 UTC
+++ src/event/modules/ngx_eventport_module.c
@@ -51,7 +51,7 @@ typedef struct  port_notify {
     void       *portnfy_user;   /* user defined */
 } port_notify_t;
 
-#if (__FreeBSD__ && __FreeBSD_version < 700005) || (NGX_DARWIN)
+#if (__FreeBSD_version < 700005) || (NGX_DARWIN)
 
 typedef struct itimerspec {     /* definition per POSIX.4 */
     struct timespec it_interval;/* timer period */
