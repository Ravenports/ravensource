--- os.h.orig	2026-07-11 12:23:46 UTC
+++ os.h
@@ -148,7 +148,7 @@ typedef char* slot_t;	/* used internally
  */
 
 #ifndef TERMCAP_BUFSIZE
-# define TERMCAP_BUFSIZE 1023
+# define TERMCAP_BUFSIZE 1024
 #endif
 
 /*
@@ -161,6 +161,6 @@ typedef char* slot_t;	/* used internally
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
