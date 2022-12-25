--- src/c_l10n.c.orig	2022-04-22 02:27:33 UTC
+++ src/c_l10n.c
@@ -484,7 +484,7 @@ char *langinfo_abmon_12() {
  */
 
 char *langinfo_decimal_point() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( DECIMAL_POINT );
@@ -498,7 +498,7 @@ char *langinfo_decimal_point() {
  */
 
 char *langinfo_thousands_sep() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( THOUSANDS_SEP );
@@ -532,7 +532,7 @@ char *langinfo_noexpr() {
  */
 
 char *langinfo_currency_symbol() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( CURRENCY_SYMBOL );
@@ -576,7 +576,7 @@ char *langinfo_t_fmt_ampm() {
  */
 
 char *langinfo_positive_sign() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( POSITIVE_SIGN );
@@ -590,7 +590,7 @@ char *langinfo_positive_sign() {
  */
 
 char *langinfo_negative_sign() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( NEGATIVE_SIGN );
@@ -604,7 +604,7 @@ char *langinfo_negative_sign() {
  */
 
 char *langinfo_int_curr_symbol() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( INT_CURR_SYMBOL );
@@ -618,7 +618,7 @@ char *langinfo_int_curr_symbol() {
  */
 
 char *langinfo_grouping() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return "\0";
 #else
    return nl_langinfo( GROUPING );
@@ -631,7 +631,7 @@ char *langinfo_grouping() {
  */
 
 char *langinfo_frac_digits() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( FRAC_DIGITS );
@@ -644,7 +644,7 @@ char *langinfo_frac_digits() {
  */
 
 char *langinfo_int_frac_digits() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( INT_FRAC_DIGITS );
@@ -657,7 +657,7 @@ char *langinfo_int_frac_digits() {
  */
 
 char *langinfo_p_cs_precedes() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( P_CS_PRECEDES );
@@ -670,7 +670,7 @@ char *langinfo_p_cs_precedes() {
  */
 
 char *langinfo_p_sep_by_space() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( P_SEP_BY_SPACE );
@@ -683,7 +683,7 @@ char *langinfo_p_sep_by_space() {
  */
 
 char *langinfo_p_sign_posn() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( P_SIGN_POSN );
@@ -696,7 +696,7 @@ char *langinfo_p_sign_posn() {
  */
 
 char *langinfo_n_cs_precedes() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( N_CS_PRECEDES );
@@ -709,7 +709,7 @@ char *langinfo_n_cs_precedes() {
  */
 
 char *langinfo_n_sep_by_space() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( N_SEP_BY_SPACE );
@@ -722,7 +722,7 @@ char *langinfo_n_sep_by_space() {
  */
 
 char *langinfo_n_sign_posn() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( N_SIGN_POSN );
@@ -735,7 +735,7 @@ char *langinfo_n_sign_posn() {
  */
 
 char *langinfo_mon_decimal_point() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( MON_DECIMAL_POINT );
@@ -749,7 +749,7 @@ char *langinfo_mon_decimal_point() {
  */
 
 char *langinfo_mon_thousands_sep() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( MON_THOUSANDS_SEP );
@@ -762,7 +762,7 @@ char *langinfo_mon_thousands_sep() {
  */
 
 char *langinfo_mon_grouping() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return "\0";
 #else
    return nl_langinfo( MON_GROUPING );
@@ -785,7 +785,7 @@ char *langinfo_era() {
  */
 
 char *langinfo_era_year() {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
    return undefined;
 #else
    return nl_langinfo( ERA_YEAR );
