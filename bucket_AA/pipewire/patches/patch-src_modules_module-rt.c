--- src/modules/module-rt.c.orig	2024-07-31 10:02:24 UTC
+++ src/modules/module-rt.c
@@ -239,6 +239,8 @@ static pid_t _gettid(void)
 	return (pid_t) gettid();
 #elif defined(__linux__)
 	return syscall(SYS_gettid);
+#elif defined(__DragonFly__)
+	return syscall(SYS_lwp_gettid);
 #elif defined(__FreeBSD__) || defined(__MidnightBSD__)
 	long pid;
 	thr_self(&pid);
