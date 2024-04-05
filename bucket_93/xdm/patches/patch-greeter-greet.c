--- greeter/greet.c.orig	2024-03-23 22:20:06 UTC
+++ greeter/greet.c
@@ -641,6 +641,7 @@ greet_user_rtn GreetUser(
     }
     DeleteXloginResources (d, *dpy);
     CloseGreet (d);
+    login = NULL;
     Debug ("Greet loop finished\n");
     /*
      * Run system-wide initialization file
