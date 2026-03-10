--- tags.c.orig	2024-07-09 15:39:50 UTC
+++ tags.c
@@ -8,7 +8,11 @@
 
 #include <sys/queue.h>
 #include <sys/stat.h>
+#if defined(__sun__)
+#include "tree.h"
+#else
 #include <sys/tree.h>
+#endif
 #include <sys/types.h>
 #include <ctype.h>
 #include <err.h>
@@ -20,12 +24,88 @@
 #include <unistd.h>
 #if defined(LIBBSD_OVERLAY) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__GLIBC__)
 #  include <libutil.h>
+#elif defined(__sun__)
+#define FPARSELN_UNESCCONT 0x01
+#define FPARSELN_UNESCREST 0x02
+#define FPARSELN_UNESCCOMM 0x04
+#define FPARSELN_UNESCESC  0x08
+#define FPARSELN_UNESCALL  0x0f
 #else
 #include <util.h>
 #endif
 
 #include "def.h"
 
+#if defined(__sun__)
+static char *
+fparseln(FILE *fp, size_t *size, size_t *lineno, const char str[3], int flags) {
+    static char *buf = NULL;
+    static size_t bufsize = 0;
+    char *line = NULL;
+    size_t linesize = 0;
+    size_t totallen = 0;
+
+    // Use defaults if str is NULL, otherwise use provided chars
+    char esc = (str) ? str[0] : '\\';
+    char con = (str) ? str[1] : '\\';
+    char com = (str) ? str[2] : '#';
+
+    if (buf == NULL) {
+        bufsize = 1024;
+        buf = malloc(bufsize);
+        if (!buf) return NULL;
+    }
+    buf[0] = '\0';
+
+    while (getline(&line, &linesize, fp) != -1) {
+        if (lineno) (*lineno)++;
+
+        size_t len = strlen(line);
+        if (len > 0 && line[len - 1] == '\n') line[--len] = '\0';
+
+        // 1. Strip comments (if not escaped)
+        for (size_t i = 0; i < len; i++) {
+            if (line[i] == com) {
+                if (i == 0 || line[i - 1] != esc) {
+                    line[i] = '\0';
+                    len = i;
+                    break;
+                }
+            }
+        }
+
+        // 2. Check for line continuation
+        int continuation = (len > 0 && line[len - 1] == con);
+        if (continuation) {
+            if (flags & FPARSELN_UNESCCONT) len--; 
+        }
+
+        // 3. Grow buffer
+        if (totallen + len + 1 > bufsize) {
+            size_t new_size = totallen + len + 1024;
+            char *new_buf = realloc(buf, new_size);
+            if (!new_buf) {
+                free(line);
+                return NULL;
+            }
+            buf = new_buf;
+            bufsize = new_size;
+        }
+
+        memcpy(buf + totallen, line, len);
+        totallen += len;
+        buf[totallen] = '\0';
+
+        if (!continuation) break;
+    }
+
+    free(line);
+    if (totallen == 0 && feof(fp)) return NULL;
+    if (size) *size = totallen;
+    return buf;
+}
+#endif
+
 struct ctag;
 
 static int               addctag(char *);
