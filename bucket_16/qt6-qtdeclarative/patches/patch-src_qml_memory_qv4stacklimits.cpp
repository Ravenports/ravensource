$NetBSD: patch-src_qml_memory_qv4stacklimits.cpp,v 1.3 2023/11/30 20:11:27 adam Exp $

Solaris uses pthread_attr_get_np for stack info.

--- src/qml/memory/qv4stacklimits.cpp.orig	2026-05-07 20:59:48 UTC
+++ src/qml/memory/qv4stacklimits.cpp
@@ -231,7 +231,7 @@ StackProperties stackPropertiesGeneric(q
 
     pthread_t thread = pthread_self();
     pthread_attr_t sattr;
-#  if defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(Q_OS_NETBSD)
+#  if defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(Q_OS_NETBSD) || defined(Q_OS_SOLARIS)
     pthread_attr_init(&sattr);
     pthread_attr_get_np(thread, &sattr);
 #  else
