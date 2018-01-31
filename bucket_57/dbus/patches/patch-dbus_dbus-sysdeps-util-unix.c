--- dbus/dbus-sysdeps-util-unix.c.orig	2017-10-30 12:26:18 UTC
+++ dbus/dbus-sysdeps-util-unix.c
@@ -42,6 +42,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <syslog.h>
 #include <sys/stat.h>
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
@@ -51,6 +52,10 @@
 #include <dirent.h>
 #include <sys/un.h>
 
+#if defined(__sun) && defined(__SVR4)
+#include <pwd.h>
+#endif
+
 #ifdef HAVE_SYS_SYSLIMITS_H
 #include <sys/syslimits.h>
 #endif
@@ -551,8 +556,31 @@ _dbus_user_at_console (const char *usern
 #ifdef DBUS_CONSOLE_AUTH_DIR
   DBusString u, f;
   dbus_bool_t result;
+#if defined(__sun) && defined(__SVR4)
+  struct passwd *passwd_entry;
+#endif
 
   result = FALSE;
+
+#if defined(__sun) && defined(__SVR4)
+  passwd_entry = getpwnam (username);
+  if (passwd_entry != NULL)
+    {
+      struct stat st;
+      uid_t uid;
+
+      uid = passwd_entry->pw_uid;
+
+      if (stat ("/dev/vt/console_user", &st) == 0 && st.st_uid == uid)
+        {
+         /*
+          * Owner is allowed to take over. Before we have real
+          * ownership in HAL, assume it's the console owner.
+          */
+          result = TRUE;
+        }
+    }
+#else
   if (!_dbus_string_init (&f))
     {
       _DBUS_SET_OOM (error);
@@ -577,6 +605,7 @@ _dbus_user_at_console (const char *usern
 
  out:
   _dbus_string_free (&f);
+#endif
 
   return result;
 #else
