--- libelftc/libelftc_dem_gnu3.c.orig	2016-01-04 02:36:38 UTC
+++ libelftc/libelftc_dem_gnu3.c
@@ -33,6 +33,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stdarg.h>
 
 #include "_libelftc.h"
 
@@ -165,6 +166,48 @@ static int	vector_type_qualifier_init(st
 static int	vector_type_qualifier_push(struct vector_type_qualifier *,
 		    enum type_qualifier);
 
+/*
+ * Compatibility funcs
+ */
+
+static int
+port_vasprintf(char **strp, const char *fmt, va_list args)
+{
+    va_list args_copy;
+    int status, needed;
+
+    va_copy(args_copy, args);
+    needed = vsnprintf(NULL, 0, fmt, args_copy);
+    va_end(args_copy);
+    if (needed < 0) {
+        *strp = NULL;
+        return needed;
+    }
+    *strp = malloc(needed + 1);
+    if (*strp == NULL)
+        return -1;
+    status = vsnprintf(*strp, needed + 1, fmt, args);
+    if (status >= 0)
+        return status;
+    else {
+        free(*strp);
+        *strp = NULL;
+        return status;
+    }
+}
+
+static int
+port_asprintf(char **strp, const char *fmt, ...)
+{
+    va_list args;
+    int status;
+
+    va_start(args, fmt);
+    status = port_vasprintf(strp, fmt, args);
+    va_end(args);
+    return status;
+}
+
 /**
  * @brief Decode the input string by IA-64 C++ ABI style.
  *
@@ -1704,7 +1747,7 @@ cpp_demangle_read_number_as_string(struc
 		return (0);
 	}
 
-	if (asprintf(str, "%ld", n) < 0) {
+	if (port_asprintf(str, "%ld", n) < 0) {
 		*str = NULL;
 		return (0);
 	}
