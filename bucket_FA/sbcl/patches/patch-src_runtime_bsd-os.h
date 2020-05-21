--- src/runtime/bsd-os.h.orig	2020-04-27 07:01:37 UTC
+++ src/runtime/bsd-os.h
@@ -22,7 +22,7 @@
 #endif
 
 typedef caddr_t os_vm_address_t;
-#if defined __NetBSD__ || defined __OpenBSD__
+#if defined __NetBSD__ || defined __OpenBSD__ || defined __DragonFly__
 typedef size_t os_vm_size_t;
 #else
 typedef vm_size_t os_vm_size_t;
