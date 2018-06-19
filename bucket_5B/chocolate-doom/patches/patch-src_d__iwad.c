--- src/d_iwad.c.orig	2018-06-19 21:08:47.831584000 +0200
+++ src/d_iwad.c	2018-06-19 21:45:29.501667000 +0200
@@ -652,13 +652,14 @@
     if (env == NULL)
     {
         // (Trailing / omitted from paths, as it is added below)
-        env = "/usr/local/share:/usr/share";
+        env = "/usr/local/share:/usr/share:/__PREFIX__/share";
     }
 
     // The "standard" location for IWADs on Unix that is supported by most
     // source ports is /usr/share/games/doom - we support this through the
     // XDG_DATA_DIRS mechanism, through which it can be overridden.
     AddIWADPath(env, "/games/doom");
+    AddIWADPath(env, "/games/doomengine");
 
     // The convention set by RBDOOM-3-BFG is to install Doom 3: BFG
     // Edition into this directory, under which includes the Doom
