--- timidity/config.h.orig	2018-04-29 19:42:45.009410000 +0200
+++ timidity/config.h	2018-04-29 19:42:59.308223000 +0200
@@ -161,7 +161,7 @@
 /* You could specify a complete path, e.g. "/etc/timidity.cfg", and
    then specify the library directory in the configuration file. */
 #define CONFIG_FILE	"timidity.cfg"
-#define CONFIG_FILE_ETC "/etc/timidity.cfg"
+#define CONFIG_FILE_ETC "__PREFIX__/etc/timidity.cfg"
 
 #if defined(__WIN32__) || defined(__OS2__)
 #define DEFAULT_PATH	"C:\\TIMIDITY"
