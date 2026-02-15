--- libseat/libseat.c.orig	2026-01-05 10:44:28.000000000 +0100
+++ libseat/libseat.c	2026-02-15 16:12:54.079456000 +0100
@@ -12,6 +12,7 @@
 
 extern const struct seat_impl seatd_impl;
 extern const struct seat_impl logind_impl;
+extern const struct seat_impl consolekit2_impl;
 extern const struct seat_impl builtin_impl;
 extern const struct seat_impl noop_impl;
 
@@ -22,6 +23,9 @@
 #ifdef LOGIND_ENABLED
 	{"logind", &logind_impl},
 #endif
+#ifdef CONSOLEKIT2_ENABLED
+	{"consolekit2", &consolekit2_impl},
+#endif
 #ifdef BUILTIN_ENABLED
 	{"builtin", &builtin_impl},
 #endif
@@ -30,7 +34,7 @@
 	{NULL, NULL},
 };
 
-#if !defined(SEATD_ENABLED) && !defined(LOGIND_ENABLED) && !defined(BUILTIN_ENABLED)
+#if !defined(SEATD_ENABLED) && !defined(LOGIND_ENABLED) && !defined(CONSOLEKIT2_ENABLED) && !defined(BUILTIN_ENABLED)
 #error At least one backend must be enabled
 #endif
 
