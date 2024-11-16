Fixes "No appropriate TLS modifier defined." error on GCC 14

--- dist/aclocal/tls.m4.orig	2013-09-09 15:35:02 UTC
+++ dist/aclocal/tls.m4
@@ -42,10 +42,10 @@ AC_DEFUN([AX_TLS], [
              pthread_key_create(&key, NULL);
          }
          static void *get_tls() {
-             return (void *)pthread_getspecific(&key);
+             return (void *)pthread_getspecific(key);
          }
          static void set_tls(void *p) {
-              pthread_setspecific(&key, p);
+              pthread_setspecific(key, p);
          }], [],
          [ac_cv_tls=pthread])
   fi
