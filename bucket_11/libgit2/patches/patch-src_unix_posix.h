--- src/unix/posix.h.orig	2020-04-01 13:49:12 UTC
+++ src/unix/posix.h
@@ -85,6 +85,11 @@ GIT_INLINE(int) p_futimes(int f, const s
 	s[1].tv_nsec = t[1].tv_usec * 1000;
 	return futimens(f, s);
 }
+#elif defined __sun__
+GIT_INLINE(int) p_futimes(int f, const struct p_timeval t[2])
+{
+	return futimesat(f, NULL, t);
+}
 #else
 # define p_futimes futimes
 #endif
