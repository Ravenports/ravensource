--- pinentry/pinentry.c.orig	2022-08-24 10:31:59 UTC
+++ pinentry/pinentry.c
@@ -50,7 +50,7 @@
 #include "pinentry.h"
 #include "password-cache.h"
 
-#ifdef INSIDE_EMACS
+#if 0
 # include "pinentry-emacs.h"
 #endif
 #ifdef FALLBACK_CURSES
@@ -1212,7 +1212,7 @@ option_handler (assuan_context_t ctx, co
     }
   else if (!strcmp (key, "allow-emacs-prompt") && !*value)
     {
-#ifdef INSIDE_EMACS
+#if 0
       pinentry_enable_emacs_cmd_handler ();
 #endif
     }
@@ -1887,7 +1887,7 @@ cmd_getinfo (assuan_context_t ctx, char
   else if (!strcmp (line, "ttyinfo"))
     {
       char emacs_status[10];
-#ifdef INSIDE_EMACS
+#if 0
       snprintf (emacs_status, sizeof emacs_status,
                 "%d", pinentry_emacs_status ());
 #else
