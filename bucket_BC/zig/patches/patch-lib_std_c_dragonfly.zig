--- lib/std/c/dragonfly.zig.orig	2023-08-03 18:22:03 UTC
+++ lib/std/c/dragonfly.zig
@@ -1143,3 +1143,51 @@ pub const POLL = struct {
     pub const HUP = 0x0010;
     pub const NVAL = 0x0020;
 };
+
+pub const mcontext_t = switch (builtin.cpu.arch) {
+    .x86_64 => extern struct {
+        mc_onstack: c_long,
+        mc_rdi: c_long,
+        mc_rsi: c_long,
+        mc_rdx: c_long,
+        mc_rcx: c_long,
+        mc_r8: c_long,
+        mc_r9: c_long,
+        mc_rax: c_long,
+        mc_rbx: c_long,
+        mc_rbp: c_long,
+        mc_r10: c_long,
+        mc_r11: c_long,
+        mc_r12: c_long,
+        mc_r13: c_long,
+        mc_r14: c_long,
+        mc_r15: c_long,
+        mc_xflags: c_long,
+        mc_trapno: c_long,
+        mc_addr: c_long,
+        mc_flags: c_long,
+        mc_err: c_long,
+        mc_rip: c_long,
+        mc_cs: c_long,
+        mc_rflags: c_long,
+        mc_rsp: c_long,
+        mc_ss: c_long,
+        mc_len: c_uint,
+        mc_fpformat: c_uint,
+        mc_ownedfp: c_uint,
+        mc_reserved: c_uint,
+        mc_unused: [8]c_uint,
+    },
+    else => struct {},
+};
+
+pub const ucontext_t = extern struct {
+    uc_sigmask: sigset_t,
+    uc_mcontext: mcontext_t,
+    uc_link: ?*ucontext_t,
+    uc_stack: stack_t,
+    uc_cofunc: void,
+    uc_arg: void,
+    __spare__: [4]c_int,
+};
+
