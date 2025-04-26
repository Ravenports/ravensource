$NetBSD: patch-boost_process_v2_pid.hpp,v 1.1 2024/10/10 14:44:17 jperkin Exp $

Needs memory for std::unique_ptr.

--- boost/process/v2/pid.hpp.orig	2025-04-03 11:37:29 UTC
+++ boost/process/v2/pid.hpp
@@ -9,6 +9,7 @@
 #include <boost/process/v2/detail/config.hpp>
 #include <boost/process/v2/detail/throw_error.hpp>
 
+#include <memory>
 #include <vector>
 #include <memory>
 
