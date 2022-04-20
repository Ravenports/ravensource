--- src/unix/posix.h.orig	2022-04-12 20:17:07 UTC
+++ src/unix/posix.h
@@ -94,6 +94,11 @@ GIT_INLINE(int) p_futimes(int f, const s
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
