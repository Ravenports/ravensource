--- src/d_iwad.c.orig	2020-06-25 03:10:06 UTC
+++ src/d_iwad.c
@@ -652,13 +652,14 @@ static void AddXdgDirs(void)
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
