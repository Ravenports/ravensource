--- def.h.orig	2018-07-13 09:16:01 UTC
+++ def.h
@@ -15,7 +15,7 @@
 
 #include	"chrdef.h"
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #  define LOGIN_NAME_MAX _POSIX_LOGIN_NAME_MAX
 #endif
 
@@ -328,6 +328,10 @@ struct undo_rec {
  * Prototypes.
  */
 
+#if defined __DragonFly__ || defined __FreeBSD__
+void		 *reallocarray(void*, size_t, size_t);
+#endif
+
 /* tty.c X */
 void		 ttinit(void);
 void		 ttreinit(void);
