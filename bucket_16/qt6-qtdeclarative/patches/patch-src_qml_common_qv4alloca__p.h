--- src/qml/common/qv4alloca_p.h.orig	2026-11-16 16:52:01 UTC
+++ src/qml/common/qv4alloca_p.h
@@ -44,7 +44,7 @@
 
 #  define Q_ALLOCA_INIT()
 #  define Q_ALLOCA_DECLARE(type, name) type *name = nullptr
-#  define Q_ALLOCA_ASSIGN(type, name, size) name = static_cast<type *>(alloca(size))
+#  define Q_ALLOCA_ASSIGN(type, name, size) name = static_cast<type *>(__builtin_alloca(size))
 
 #else
 #  include <memory>
