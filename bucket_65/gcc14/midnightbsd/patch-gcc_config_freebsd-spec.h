--- gcc/config/freebsd-spec.h.orig	2024-08-01 08:17:14 UTC
+++ gcc/config/freebsd-spec.h
@@ -37,6 +37,7 @@ see the files COPYING3 and COPYING.RUNTI
   do									\
     {									\
 	builtin_define_with_int_value ("__FreeBSD__", FBSD_MAJOR);	\
+	builtin_define_with_int_value ("__MidnightBSD__", 3);		\
 	builtin_define_std ("unix");					\
 	builtin_define ("__KPRINTF_ATTRIBUTE__");		       	\
 	builtin_assert ("system=unix");					\
