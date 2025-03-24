--- greeter/greet.c.orig	2025-03-09 01:13:49 UTC
+++ greeter/greet.c
@@ -641,6 +641,7 @@ greet_user_rtn GreetUser(
     }
     DeleteXloginResources (d, *dpy);
     CloseGreet (d);
+    login = NULL;
     Debug ("Greet loop finished\n");
     /*
      * Run system-wide initialization file
