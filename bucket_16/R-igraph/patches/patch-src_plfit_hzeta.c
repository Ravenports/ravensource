NetBSD does not support log1pl

--- src/plfit/hzeta.c.orig	2021-10-14 20:57:32 UTC
+++ src/plfit/hzeta.c
@@ -393,7 +393,7 @@ double hsl_sf_hzeta_deriv2(const double
 
 static inline
 double hsl_sf_hZeta0_zed(const double s, const double q) {
-#if 1
+#if !defined(__NetBSD__)
 	const long double ld_q=(long double)(q);
 	const long double ld_s=(long double)(s);
 	const long double ld_log1prq=log1pl(1.0L/ld_q);
@@ -468,7 +468,7 @@ int hsl_sf_hZeta0(const double s, const
 
 static inline
 double hsl_sf_hZeta1_zed(const double s, const double q) {
-#if 1
+#if !defined(__NetBSD__) 
 	const long double ld_q=(long double)(q);
 	const long double ld_s=(long double)(s);
 	const long double ld_sm1=ld_s-1.0L;
