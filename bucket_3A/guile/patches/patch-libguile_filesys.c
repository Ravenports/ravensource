--- libguile/filesys.c.orig	2020-05-30 20:06:44 UTC
+++ libguile/filesys.c
@@ -1519,6 +1519,9 @@ SCM_DEFINE (scm_i_mkstemp, "mkstemp!", 1
       mode_bits = scm_i_mode_bits (mode);
     }
 
+#if defined __FreeBSD__ || defined __DragonFly__
+  open_flags &= O_APPEND | O_DIRECT | O_SHLOCK | O_EXLOCK | O_CLOEXEC;
+#endif
   SCM_SYSCALL (rv = mkostemp (c_tmpl, open_flags));
   if (rv == -1)
     SCM_SYSERROR;
