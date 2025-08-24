--- sql/sys_vars.cc.orig	2025-07-10 14:20:26 UTC
+++ sql/sys_vars.cc
@@ -2238,7 +2238,7 @@ static Sys_var_ulong Sys_interactive_tim
     "The number of seconds the server waits for activity on an interactive "
     "connection before closing it",
     SESSION_VAR(net_interactive_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
 
 static Sys_var_ulong Sys_join_buffer_size(
     "join_buffer_size", "The size of the buffer that is used for full joins",
@@ -3036,7 +3036,7 @@ static Sys_var_ulong Sys_net_read_timeou
     "Number of seconds to wait for more data from a connection before "
     "aborting the read",
     SESSION_VAR(net_read_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
     NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(nullptr),
     ON_UPDATE(fix_net_read_timeout));
 
@@ -3057,7 +3057,7 @@ static Sys_var_ulong Sys_net_write_timeo
     "Number of seconds to wait for a block to be written to a connection "
     "before aborting the write",
     SESSION_VAR(net_write_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
     NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(nullptr),
     ON_UPDATE(fix_net_write_timeout));
 
@@ -5084,7 +5084,7 @@ static Sys_var_ulong Sys_net_wait_timeou
     "The number of seconds the server waits for activity on a "
     "connection before closing it",
     SESSION_VAR(net_wait_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, IF_WIN(INT_MAX32 / 1000, LONG_TIMEOUT)),
+    VALID_RANGE(1, INT_MAX32 / 1000),
     DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
 
 static Sys_var_plugin Sys_default_storage_engine(
