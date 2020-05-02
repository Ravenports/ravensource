--- util/coroutine-ucontext.c.orig	2020-04-28 16:49:25 UTC
+++ util/coroutine-ucontext.c
@@ -158,7 +158,15 @@ Coroutine *qemu_coroutine_new(void)
                 2, arg.i[0], arg.i[1]);
 
     /* swapcontext() in, siglongjmp() back out */
-    if (!sigsetjmp(old_env, 0)) {
+    /* Save signal mask in this sigsetjmp, because makecontext on DragonFly
+     * leaves all signals blocked when entering the new context with
+     * swapcontext.
+     * Workaround this, by just having the signal mask restored by the
+     * siglongjmp that brings us back from qemu_coroutine_new().
+     * XXX Remove this workaround when the makecontext behaviour is fixed
+     *     on DragonFly.
+     */
+    if (!sigsetjmp(old_env, 1)) {
         start_switch_fiber(&fake_stack_save, co->stack, co->stack_size);
         swapcontext(&old_uc, &uc);
     }
