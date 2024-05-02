--- src/qml/common/qv4alloca_p.h.orig	2024-03-22 15:59:36 UTC
+++ src/qml/common/qv4alloca_p.h
@@ -42,8 +42,13 @@
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
 QT_BEGIN_NAMESPACE
