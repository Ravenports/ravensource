--- src/c_l10n.c.orig	2024-07-01 16:16:15 UTC
+++ src/c_l10n.c
@@ -485,7 +485,7 @@ char *langinfo_abmon_12() {
  */
 
 char *langinfo_decimal_point() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -501,7 +501,7 @@ char *langinfo_decimal_point() {
  */
 
 char *langinfo_thousands_sep() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -537,7 +537,7 @@ char *langinfo_noexpr() {
  */
 
 char *langinfo_currency_symbol() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -583,7 +583,7 @@ char *langinfo_t_fmt_ampm() {
  */
 
 char *langinfo_positive_sign() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -599,7 +599,7 @@ char *langinfo_positive_sign() {
  */
 
 char *langinfo_negative_sign() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -615,7 +615,7 @@ char *langinfo_negative_sign() {
  */
 
 char *langinfo_int_curr_symbol() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -631,7 +631,7 @@ char *langinfo_int_curr_symbol() {
  */
 
 char *langinfo_grouping() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return "\0";
 #elif !defined(__USE_GNU)
    return "\0";
@@ -646,7 +646,7 @@ char *langinfo_grouping() {
  */
 
 char *langinfo_frac_digits() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -661,7 +661,7 @@ char *langinfo_frac_digits() {
  */
 
 char *langinfo_int_frac_digits() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -676,7 +676,7 @@ char *langinfo_int_frac_digits() {
  */
 
 char *langinfo_p_cs_precedes() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -691,7 +691,7 @@ char *langinfo_p_cs_precedes() {
  */
 
 char *langinfo_p_sep_by_space() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -706,7 +706,7 @@ char *langinfo_p_sep_by_space() {
  */
 
 char *langinfo_p_sign_posn() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -721,7 +721,7 @@ char *langinfo_p_sign_posn() {
  */
 
 char *langinfo_n_cs_precedes() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -736,7 +736,7 @@ char *langinfo_n_cs_precedes() {
  */
 
 char *langinfo_n_sep_by_space() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -751,7 +751,7 @@ char *langinfo_n_sep_by_space() {
  */
 
 char *langinfo_n_sign_posn() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -766,7 +766,7 @@ char *langinfo_n_sign_posn() {
  */
 
 char *langinfo_mon_decimal_point() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -782,7 +782,7 @@ char *langinfo_mon_decimal_point() {
  */
 
 char *langinfo_mon_thousands_sep() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
@@ -797,7 +797,7 @@ char *langinfo_mon_thousands_sep() {
  */
 
 char *langinfo_mon_grouping() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return "\0";
 #elif !defined(__USE_GNU)
    return "\0";
@@ -822,7 +822,7 @@ char *langinfo_era() {
  */
 
 char *langinfo_era_year() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__linux__)
    return undefined;
 #elif !defined(__USE_GNU)
    return undefined;
