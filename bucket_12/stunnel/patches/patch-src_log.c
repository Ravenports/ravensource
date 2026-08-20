--- src/log.c.orig	2026-07-31 12:19:55 UTC
+++ src/log.c
@@ -275,7 +275,7 @@ NOEXPORT void log_raw(SERVICE_OPTIONS *o
     switch(log_mode) {
     case LOG_MODE_CONFIGURED:
         size=strlen(stamp)+strlen(id)+strlen(text)+4;
-        line=alloca(size);
+        line=__builtin_alloca(size);
         snprintf(line, size, "%s %s: %s", stamp, id, text);
         if(level<=opt->log_level) {
 #if !defined(USE_WIN32) && !defined(__vms)
@@ -295,7 +295,7 @@ NOEXPORT void log_raw(SERVICE_OPTIONS *o
             return;
         /* don't log the id or the time stamp */
         size=strlen(text)+5;
-        line=alloca(size);
+        line=__builtin_alloca(size);
         if(level>=LOG_EMERG && level<=LOG_NOTICE)
             snprintf(line, size, "[%c] %s", "***!:."[level], text);
         else /* invalid level */
