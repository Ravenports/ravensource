--- lib/libpam/openpam_ttyconv.c.orig	2019-02-24 20:15:19 UTC
+++ lib/libpam/openpam_ttyconv.c
@@ -57,6 +57,30 @@
 #include "openpam_impl.h"
 #include "openpam_strlset.h"
 
+#ifndef timeradd
+#define timeradd(tvp, uvp, vvp)						\
+	do {								\
+		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\
+		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;	\
+		if ((vvp)->tv_usec >= 1000000) {			\
+			(vvp)->tv_sec++;				\
+			(vvp)->tv_usec -= 1000000;			\
+		}							\
+	} while (0)
+#endif
+
+#ifndef timersub
+#define timersub(tvp, uvp, vvp)						\
+	do {								\
+		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\
+		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\
+		if ((vvp)->tv_usec < 0) {				\
+			(vvp)->tv_sec--;				\
+			(vvp)->tv_usec += 1000000;			\
+		}							\
+	} while (0)
+#endif
+
 int openpam_ttyconv_timeout = 0;
 
 static volatile sig_atomic_t caught_signal;
