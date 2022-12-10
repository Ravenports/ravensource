--- greeter/greet.c.orig	2022-12-03 21:38:28 UTC
+++ greeter/greet.c
@@ -639,6 +639,7 @@ greet_user_rtn GreetUser(
     }
     DeleteXloginResources (d, *dpy);
     CloseGreet (d);
+    login = NULL;
     Debug ("Greet loop finished\n");
     /*
      * Run system-wide initialization file
