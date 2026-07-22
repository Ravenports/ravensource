--- src/gallium/auxiliary/driver_ddebug/dd_draw.c.orig	2026-05-19 14:27:16 UTC
+++ src/gallium/auxiliary/driver_ddebug/dd_draw.c
@@ -92,7 +92,7 @@ dd_parse_apitrace_marker(const char *str
       return;
 
    /* Make it zero-terminated. */
-   s = alloca(len + 1);
+   s = __builtin_alloca(len + 1);
    memcpy(s, string, len);
    s[len] = 0;
 
