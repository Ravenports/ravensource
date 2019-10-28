--- src/runtime/x86-64-bsd-os.c.orig	2019-10-26 11:03:42 UTC
+++ src/runtime/x86-64-bsd-os.c
@@ -148,6 +148,13 @@ os_flush_icache(os_vm_address_t address,
 {
 }
 
+#if defined(LISP_FEATURE_SB_THREAD) && (defined __DragonFly__ || defined __FreeBSD__)
+void
+arch_os_load_ldt(struct thread *thread)
+{
+}
+#endif
+
 int arch_os_thread_init(struct thread *thread) {
 #ifdef LISP_FEATURE_SB_THREAD
 #ifdef LISP_FEATURE_GCC_TLS
