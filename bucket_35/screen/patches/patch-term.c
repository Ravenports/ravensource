--- term.c.orig	2019-10-01 22:08:00 UTC
+++ term.c
@@ -197,6 +197,7 @@ struct term term[T_N] =
   { "F1", T_STR  }, KMAPDEF("\033[23~")
   { "F2", T_STR  }, KMAPDEF("\033[24~")
   /* extra keys for vt220 (David.Leonard@it.uq.edu.au) */
+/* define T_FEXTRA */
   { "F3", T_STR  },
   { "F4", T_STR  },
   { "F5", T_STR  },
