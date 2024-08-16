--- src/d_iwad.c.intermediate	2024-08-16 01:30:22 UTC
+++ src/d_iwad.c
@@ -677,13 +677,14 @@ static void AddXdgDirs(void)
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
     AddIWADPath(env, "/doom");
 
     // The convention set by RBDOOM-3-BFG is to install Doom 3: BFG
