--- lib/localename.c.orig	2016-12-02 16:41:57 UTC
+++ lib/localename.c
@@ -2712,7 +2712,7 @@ gl_locale_name_thread_unsafe (int catego
              nl_langinfo (_NL_LOCALE_NAME (category)).  */
           name = thread_locale->__names[category];
         return name;
-#  elif defined __FreeBSD__ || (defined __APPLE__ && defined __MACH__)
+#  elif defined __FreeBSD__ || defined __DragonFly__ || (defined __APPLE__ && defined __MACH__)
         /* FreeBSD, Mac OS X */
         int mask;
 
