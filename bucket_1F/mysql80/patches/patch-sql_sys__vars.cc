--- sql/sys_vars.cc.orig	2019-01-25 22:33:03 UTC
+++ sql/sys_vars.cc
@@ -1930,7 +1930,7 @@ static Sys_var_ulong Sys_interactive_tim
     "The number of seconds the server waits for activity on an interactive "
     "connection before closing it",
     SESSION_VAR(net_interactive_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
 
 static Sys_var_ulong Sys_join_buffer_size(
     "join_buffer_size", "The size of the buffer that is used for full joins",
@@ -2714,7 +2714,7 @@ static Sys_var_ulong Sys_net_read_timeou
     "Number of seconds to wait for more data from a connection before "
     "aborting the read",
     SESSION_VAR(net_read_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
     NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(0),
     ON_UPDATE(fix_net_read_timeout));
 
@@ -2735,7 +2735,7 @@ static Sys_var_ulong Sys_net_write_timeo
     "Number of seconds to wait for a block to be written to a connection "
     "before aborting the write",
     SESSION_VAR(net_write_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
     NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(0),
     ON_UPDATE(fix_net_write_timeout));
 
@@ -4251,7 +4251,7 @@ static Sys_var_charptr Sys_tls_version(
     READ_ONLY GLOBAL_VAR(opt_tls_version), SSL_OPT(OPT_TLS_VERSION),
     IN_FS_CHARSET, "TLSv1,TLSv1.1,TLSv1.2");
 
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
 static bool update_fips_mode(sys_var *, THD *, enum_var_type) {
   char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   if (set_fips_mode(opt_ssl_fips_mode, ssl_err_string) != 1) {
@@ -4264,7 +4264,7 @@ static bool update_fips_mode(sys_var *,
 }
 #endif
 
-#ifdef HAVE_WOLFSSL
+#if defined(HAVE_WOLFSSL) || defined(LIBRESSL_VERSION_NUMBER)
 static const char *ssl_fips_mode_names[] = {"OFF", 0};
 #else
 static const char *ssl_fips_mode_names[] = {"OFF", "ON", "STRICT", 0};
@@ -4280,7 +4280,7 @@ static Sys_var_enum Sys_ssl_fips_mode(
     GLOBAL_VAR(opt_ssl_fips_mode), SSL_OPT(OPT_SSL_FIPS_MODE),
     ssl_fips_mode_names, DEFAULT(0), NO_MUTEX_GUARD, NOT_IN_BINLOG,
     ON_CHECK(NULL),
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
     ON_UPDATE(update_fips_mode),
 #else
     ON_UPDATE(NULL),
@@ -4589,7 +4589,7 @@ static Sys_var_ulong Sys_net_wait_timeou
     "The number of seconds the server waits for activity on a "
     "connection before closing it",
     SESSION_VAR(net_wait_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, IF_WIN(INT_MAX32 / 1000, LONG_TIMEOUT)),
+    VALID_RANGE(1, INT_MAX32 / 1000),
     DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
 
 static Sys_var_plugin Sys_default_storage_engine(
