--- libguile/filesys.c.orig	2024-03-17 09:08:25 UTC
+++ libguile/filesys.c
@@ -1894,6 +1894,9 @@ SCM_DEFINE (scm_i_mkstemp, "mkstemp", 1,
       mode_bits = scm_i_mode_bits (mode);
     }
 
+#if defined __FreeBSD__ || defined __DragonFly__
+  open_flags &= O_APPEND | O_DIRECT | O_SHLOCK | O_EXLOCK | O_CLOEXEC;
+#endif
   SCM_SYSCALL (rv = mkostemp (c_tmpl, open_flags));
   if (rv == -1)
     SCM_SYSERROR;
