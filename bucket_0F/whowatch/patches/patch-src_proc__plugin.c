--- src/proc_plugin.c.orig	2018-04-11 06:10:50 UTC
+++ src/proc_plugin.c
@@ -33,7 +33,6 @@
 #if defined(HAVE_LIBKVM) && defined(HAVE_STDINT_H) && defined(HAVE_KVM_H)
 #include <stdint.h>
 #include <kvm.h>
-kvm_t *kd;
 extern int can_use_kvm;
 #endif
 
