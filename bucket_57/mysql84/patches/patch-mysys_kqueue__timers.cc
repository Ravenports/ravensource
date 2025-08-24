$NetBSD: patch-mysys_kqueue__timers.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* support pre NetBSD 10 __intptr_t udata type
* Fix for systems whcich do not define EVFILT_USER

--- mysys/kqueue_timers.cc.orig	2025-07-10 14:20:26 UTC
+++ mysys/kqueue_timers.cc
@@ -41,6 +41,18 @@
 #include "mysys_err.h"
 #include "mysys_priv.h" /* key_thread_timer_notifier */
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ < 999001400
+#define KEVENT_UDATA_TYPE_CAST (__intptr_t)
+#else
+#define KEVENT_UDATA_TYPE_CAST
+#endif
+#else
+#define KEVENT_UDATA_TYPE_CAST
+#endif
+
+
 /* Kernel event queue file descriptor. */
 static int kq_fd = -1;
 
@@ -70,10 +82,12 @@ static void *timer_notify_thread_func(vo
     }
 
     if (kev.filter == EVFILT_TIMER) {
-      timer = static_cast<my_timer_t *>(kev.udata);
+      timer = static_cast<my_timer_t *>((void *)kev.udata);
       assert(timer->id == kev.ident);
       timer->notify_function(timer);
+#ifdef EVFILT_USER
     } else if (kev.filter == EVFILT_USER)
+#endif
       break;
   }
 
@@ -92,7 +106,9 @@ static void *timer_notify_thread_func(vo
 static int start_helper_thread(void) {
   struct kevent kev;
 
+#ifdef EVFILT_USER
   EV_SET(&kev, 0, EVFILT_USER, EV_ADD, 0, 0, 0);
+#endif
 
   if (kevent(kq_fd, &kev, 1, nullptr, 0, nullptr) < 0) {
     my_message_local(ERROR_LEVEL, EE_FAILED_TO_CREATE_TIMER, errno);
@@ -135,7 +151,9 @@ int my_timer_initialize(void) {
 void my_timer_deinitialize(void) {
   struct kevent kev;
 
+#ifdef EVFILT_USER
   EV_SET(&kev, 0, EVFILT_USER, 0, NOTE_TRIGGER, 0, 0);
+#endif
 
   if (kevent(kq_fd, &kev, 1, nullptr, 0, nullptr) < 0)
     my_message_local(ERROR_LEVEL,
@@ -166,7 +184,7 @@ int my_timer_create(my_timer_t *timer) {
 int my_timer_set(my_timer_t *timer, unsigned long time) {
   struct kevent kev;
 
-  EV_SET(&kev, timer->id, EVFILT_TIMER, EV_ADD | EV_ONESHOT, 0, time, timer);
+  EV_SET(&kev, timer->id, EVFILT_TIMER, EV_ADD | EV_ONESHOT, 0, time,KEVENT_UDATA_TYPE_CAST timer);
 
   return kevent(kq_fd, &kev, 1, nullptr, 0, nullptr);
 }
