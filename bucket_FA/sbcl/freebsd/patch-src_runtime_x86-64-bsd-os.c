--- src/runtime/x86-64-bsd-os.c.orig	2019-08-26 08:51:58 UTC
+++ src/runtime/x86-64-bsd-os.c
@@ -148,6 +148,13 @@ os_flush_icache(os_vm_address_t address,
 {
 }
 
+#ifdef LISP_FEATURE_SB_THREAD
+void
+arch_os_load_ldt(struct thread *thread)
+{
+}
+#endif
+
 int arch_os_thread_init(struct thread *thread) {
 #ifdef LISP_FEATURE_SB_THREAD
 #ifdef LISP_FEATURE_GCC_TLS
