--- utmp.c.orig	2023-08-16 00:29:26 UTC
+++ utmp.c
@@ -38,6 +38,9 @@
 #include <utempter.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#define MyBSD
+#endif
 
 extern struct display *display;
 #ifdef CAREFULUTMP
@@ -409,12 +412,14 @@ struct win *wi;
   register slot_t slot;
   struct utmp u;
   int saved_ut;
+#ifndef MyBSD
 #ifdef UTHOST
   char *p;
   char host[sizeof(D_loginhost) + 15];
 #else
   char *host = 0;
 #endif /* UTHOST */
+#endif /* !MyBSD */
 
   wi->w_slot = (slot_t)0;
   if (!utmpok || wi->w_type != W_TYPE_PTY)
@@ -435,6 +440,7 @@ struct win *wi;
     makeuser(&u, stripdev(wi->w_tty), LoginName, wi->w_pid);
 
 #ifdef UTHOST
+#ifndef MyBSD
   host[sizeof(host) - 15] = '\0';
   if (display)
     {
@@ -477,9 +483,19 @@ struct win *wi;
 # if !defined(_SEQUENT_) && !defined(sequent)
   strncpy(u.ut_host, host, sizeof(u.ut_host));
 # endif
+#else  /* ! MyBSD */
+# if !defined(_SEQUENT_) && !defined(sequent)
+  if (display)
+    strncpy(u.ut_host, D_loginhost, sizeof(u.ut_host));
+# endif
+#endif /* ! MyBSD */
 #endif /* UTHOST */
 
+#ifdef MyBSD
+  if (pututslot(slot, &u, D_loginhost, wi) == 0)
+#else
   if (pututslot(slot, &u, host, wi) == 0)
+#endif
     {
       Msg(errno,"Could not write %s", UtmpName);
       UT_CLOSE;
@@ -607,7 +623,7 @@ makedead(u)
 struct utmp *u;
 {
   u->ut_type = DEAD_PROCESS;
-#if (!defined(linux) || defined(EMPTY)) && !defined(__CYGWIN__)
+#if (!defined(linux) || defined(EMPTY)) && !defined(__CYGWIN__) && !defined(MyBSD)
   u->ut_exit.e_termination = 0;
   u->ut_exit.e_exit = 0;
 #endif
@@ -640,7 +656,11 @@ int pid;
   /* must use temp variable because of NetBSD/sparc64, where
    * ut_xtime is long(64) but time_t is int(32) */
   (void)time(&now);
+#ifdef MyBSD
+  u->ut_tv.tv_sec = now;
+#else
   u->ut_time = now;
+#endif
 }
 
 static slot_t
@@ -752,7 +772,11 @@ int pid;
   strncpy(u->ut_line, line, sizeof(u->ut_line));
   strncpy(u->ut_name, user, sizeof(u->ut_name));
   (void)time(&now);
+#ifdef MyBSD
+  u->ut_tv.tv_sec = now;
+#else
   u->ut_time = now;
+#endif
 }
 
 static slot_t
