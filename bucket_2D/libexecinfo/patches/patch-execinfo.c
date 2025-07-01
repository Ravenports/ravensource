--- execinfo.c.orig	2004-07-19 05:21:09 UTC
+++ execinfo.c
@@ -69,7 +69,8 @@ backtrace(void **buffer, int size)
 char **
 backtrace_symbols(void *const *buffer, int size)
 {
-    int i, clen, alen, offset;
+    size_t clen, alen;
+    int i, offset;
     char **rval;
     char *cp;
     Dl_info info;
@@ -78,7 +79,6 @@ backtrace_symbols(void *const *buffer, i
     rval = malloc(clen);
     if (rval == NULL)
         return NULL;
-    (char **)cp = &(rval[size]);
     for (i = 0; i < size; i++) {
         if (dladdr(buffer[i], &info) != 0) {
             if (info.dli_sname == NULL)
@@ -92,14 +92,14 @@ backtrace_symbols(void *const *buffer, i
                    2 +                      /* " <" */
                    strlen(info.dli_sname) + /* "function" */
                    1 +                      /* "+" */
-                   D10(offset) +            /* "offset */
+                   10 +                     /* "offset */
                    5 +                      /* "> at " */
                    strlen(info.dli_fname) + /* "filename" */
                    1;                       /* "\0" */
             rval = realloc_safe(rval, clen + alen);
             if (rval == NULL)
                 return NULL;
-            snprintf(cp, alen, "%p <%s+%d> at %s",
+            snprintf((char *) rval + clen, alen, "%p <%s+%d> at %s",
               buffer[i], info.dli_sname, offset, info.dli_fname);
         } else {
             alen = 2 +                      /* "0x" */
@@ -108,12 +108,15 @@ backtrace_symbols(void *const *buffer, i
             rval = realloc_safe(rval, clen + alen);
             if (rval == NULL)
                 return NULL;
-            snprintf(cp, alen, "%p", buffer[i]);
+            snprintf((char *) rval + clen, alen, "%p", buffer[i]);
         }
-        rval[i] = cp;
-        cp += alen;
+        rval[i] = (char *) clen;
+        clen += alen;
     }
 
+    for (i = 0; i < size; i++)
+        rval[i] += (long) rval;
+
     return rval;
 }
 
@@ -141,7 +144,7 @@ backtrace_symbols_fd(void *const *buffer
                   5 +                      /* "> at " */
                   strlen(info.dli_fname) + /* "filename" */
                   2;                       /* "\n\0" */
-            buf = alloca(len);
+            buf = __builtin_alloca(len);
             if (buf == NULL)
                 return;
             snprintf(buf, len, "%p <%s+%d> at %s\n",
@@ -150,11 +153,11 @@ backtrace_symbols_fd(void *const *buffer
             len = 2 +                      /* "0x" */
                   (sizeof(void *) * 2) +   /* "01234567" */
                   2;                       /* "\n\0" */
-            buf = alloca(len);
+            buf = __builtin_alloca(len);
             if (buf == NULL)
                 return;
             snprintf(buf, len, "%p\n", buffer[i]);
         }
-        write(fd, buf, len - 1);
+        write(fd, buf, strlen(buf));
     }
 }
