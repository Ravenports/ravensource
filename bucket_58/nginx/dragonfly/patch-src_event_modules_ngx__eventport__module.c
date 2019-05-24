--- src/event/modules/ngx_eventport_module.c.orig	2016-05-24 15:54:42 UTC
+++ src/event/modules/ngx_eventport_module.c
@@ -49,7 +49,7 @@ typedef struct  port_notify {
     void       *portnfy_user;   /* user defined */
 } port_notify_t;
 
-#if (__FreeBSD__ && __FreeBSD_version < 700005) || (NGX_DARWIN)
+#if (__FreeBSD_version < 700005) || (NGX_DARWIN)
 
 typedef struct itimerspec {     /* definition per POSIX.4 */
     struct timespec it_interval;/* timer period */
