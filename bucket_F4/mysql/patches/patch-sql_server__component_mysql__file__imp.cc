--- sql/server_component/mysql_file_imp.cc.orig	2025-12-15 13:32:53 UTC
+++ sql/server_component/mysql_file_imp.cc
@@ -23,6 +23,7 @@ Foundation, Inc., 51 Franklin St, Fifth
 
 #include "sql/server_component/mysql_file_imp.h"
 
+#include <sys/stat.h> // for S_IRUSR, S_IWGRP, etc
 #include <fcntl.h>
 #include <mysql/components/service_implementation.h>
 #include "my_io.h"
