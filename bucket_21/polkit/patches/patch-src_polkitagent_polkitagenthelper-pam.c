Fix build on NetBSD.
https://github.com/polkit-org/polkit/pull/624

Combined with FreeBSD's FPC patch

--- src/polkitagent/polkitagenthelper-pam.c.orig	2025-12-17 16:14:53 UTC
+++ src/polkitagent/polkitagenthelper-pam.c
@@ -38,7 +38,7 @@
 #    define SO_PEERPIDFD 0x404B
 #  elif defined(__sparc__)
 #    define SO_PEERPIDFD 0x0056
-#  else
+#  elif defined(__linux__)
 #    define SO_PEERPIDFD 77
 #  endif
 #endif
@@ -137,11 +137,14 @@ main (int argc, char *argv[])
       goto error;
     }
 
+#ifdef SO_PEERPIDFD
   /* We are socket activated and the socket has been set up as stdio/stdout, read user from it */
   if (argv[1] != NULL && strcmp (argv[1], "--socket-activated") == 0)
     {
       socklen_t socklen = sizeof(int);
+# ifdef SO_PEERCRED
       struct ucred ucred;
+# endif
 
       user_to_auth_free = read_cookie (argc, argv);
       if (!user_to_auth_free)
@@ -165,8 +168,12 @@ main (int argc, char *argv[])
           goto error;
         }
 
+# ifdef SO_PEERCRED
       socklen = sizeof(ucred);
       rc = getsockopt(STDIN_FILENO, SOL_SOCKET, SO_PEERCRED, &ucred, &socklen);
+# else
+	rc = -1;
+# endif
       if (rc < 0)
         {
           syslog (LOG_ERR, "Unable to get credentials from socket");
@@ -174,9 +181,12 @@ main (int argc, char *argv[])
           goto error;
         }
 
+# ifdef SO_PEERCRED
       uid = ucred.uid;
+# endif
     }
   else
+#endif
     user_to_auth = argv[1];
 
   cookie = read_cookie (argc, argv);
