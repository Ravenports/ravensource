--- src/log.c.orig	2025-11-14 12:52:51 UTC
+++ src/log.c
@@ -198,7 +198,7 @@ void s_vlog(int level, const char *forma
         len=vsnprintf(NULL, 0, format, ap);
         if(len>1024)
             len=1024;
-        text=alloca((size_t)len+1);
+        text=__builtin_alloca((size_t)len+1);
         len=vsnprintf(text, (size_t)len+1, format, aq);
         va_end(aq);
         while(len>0 && text[len-1]=='\n')
@@ -284,7 +284,7 @@ NOEXPORT void log_raw(SERVICE_OPTIONS *o
     switch(log_mode) {
     case LOG_MODE_CONFIGURED:
         size=strlen(stamp)+strlen(id)+strlen(text)+4;
-        line=alloca(size);
+        line=__builtin_alloca(size);
         snprintf(line, size, "%s %s: %s", stamp, id, text);
         if(level<=opt->log_level) {
 #if !defined(USE_WIN32) && !defined(__vms)
@@ -302,7 +302,7 @@ NOEXPORT void log_raw(SERVICE_OPTIONS *o
     case LOG_MODE_ERROR:
         /* don't log the id or the time stamp */
         size=strlen(text)+5;
-        line=alloca(size);
+        line=__builtin_alloca(size);
         if(level>=0 && level<=7) /* just in case */
             snprintf(line, size, "[%c] %s", "***!:.  "[level], text);
         else
