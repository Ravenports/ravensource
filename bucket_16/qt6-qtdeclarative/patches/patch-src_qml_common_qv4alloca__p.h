--- src/qml/common/qv4alloca_p.h.orig	2025-01-24 06:04:38 UTC
+++ src/qml/common/qv4alloca_p.h
@@ -43,8 +43,13 @@
 #define Q_ALLOCA_DECLARE(type, name) \
     type *name = 0
 
+# if defined(__NetBSD__)
+#define Q_ALLOCA_ASSIGN(type, name, size) \
+    name = static_cast<type*>(__builtin_alloca(size))
+# else
 #define Q_ALLOCA_ASSIGN(type, name, size) \
     name = static_cast<type*>(alloca(size))
+# endif
 
 #else
 #  include <memory>
