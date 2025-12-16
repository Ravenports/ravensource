--- pcntl.c.orig	2025-11-18 08:02:20 UTC
+++ pcntl.c
@@ -437,8 +437,13 @@ PHP_FUNCTION(pcntl_waitid)
 		}
 		struct rusage rusage;
 # if defined(HAVE_WAIT6) /* FreeBSD */
+#    if defined(__NetBSD__)
+		struct wrusage wrusage;
+		memset(&wrusage, 0, sizeof(struct wrusage));
+#    else
 		struct __wrusage wrusage;
 		memset(&wrusage, 0, sizeof(struct __wrusage));
+#    endif
 		pid_t pid = wait6((idtype_t) idtype, (id_t) id, &status, (int) options, &wrusage, &siginfo);
 		status = pid > 0 ? 0 : pid;
 		memcpy(&rusage, &wrusage.wru_self, sizeof(struct rusage));
