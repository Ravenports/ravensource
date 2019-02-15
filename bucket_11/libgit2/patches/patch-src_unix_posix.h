--- src/unix/posix.h.orig	2019-02-14 16:36:00 UTC
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
