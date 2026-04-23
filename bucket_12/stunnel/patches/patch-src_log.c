--- src/log.c.orig	2026-03-19 19:18:37 UTC
+++ src/log.c
@@ -194,7 +194,7 @@ void s_vlog(int level, const char *forma
         va_end(aq);
         if(len>1024)
             len=1024;
-        text=alloca((size_t)len+1);
+        text=__builtin_alloca((size_t)len+1);
         va_copy(aq, ap);
         len=vsnprintf(text, (size_t)len+1, format, aq);
         va_end(aq);
@@ -282,7 +282,7 @@ NOEXPORT void log_raw(SERVICE_OPTIONS *o
     switch(log_mode) {
     case LOG_MODE_CONFIGURED:
         size=strlen(stamp)+strlen(id)+strlen(text)+4;
-        line=alloca(size);
+        line=__builtin_alloca(size);
         snprintf(line, size, "%s %s: %s", stamp, id, text);
         if(level<=opt->log_level) {
 #if !defined(USE_WIN32) && !defined(__vms)
@@ -302,7 +302,7 @@ NOEXPORT void log_raw(SERVICE_OPTIONS *o
             return;
         /* don't log the id or the time stamp */
         size=strlen(text)+5;
-        line=alloca(size);
+        line=__builtin_alloca(size);
         if(level>=LOG_EMERG && level<=LOG_NOTICE)
             snprintf(line, size, "[%c] %s", "***!:."[level], text);
         else /* invalid level */
