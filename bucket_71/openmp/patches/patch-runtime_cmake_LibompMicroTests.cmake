--- runtime/cmake/LibompMicroTests.cmake.orig	2018-12-09 16:40:33 UTC
+++ runtime/cmake/LibompMicroTests.cmake
@@ -171,7 +171,7 @@ add_custom_command(
 add_custom_target(libomp-test-deps DEPENDS test-deps/.success)
 set(libomp_expected_library_deps)
 if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
-  set(libomp_expected_library_deps libc.so.7 libthr.so.3)
+  set(libomp_expected_library_deps libc.so.7 libthr.so.3 libm.so.5)
   libomp_append(libomp_expected_library_deps libhwloc.so.5 LIBOMP_USE_HWLOC)
 elseif(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
   set(libomp_expected_library_deps libc.so.12 libpthread.so.1 libm.so.0)
