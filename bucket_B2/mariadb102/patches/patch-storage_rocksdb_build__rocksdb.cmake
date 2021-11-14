--- storage/rocksdb/build_rocksdb.cmake.orig	2021-11-05 18:07:43 UTC
+++ storage/rocksdb/build_rocksdb.cmake
@@ -76,10 +76,6 @@ if(ZSTD_FOUND AND (NOT WITH_ROCKSDB_ZSTD
   SET(CMAKE_REQUIRED_LIBRARIES zstd)
   CHECK_FUNCTION_EXISTS(ZDICT_trainFromBuffer ZSTD_VALID)
   UNSET(CMAKE_REQUIRED_LIBRARIES)
-  if (WITH_ROCKSDB_ZSTD STREQUAL "ON" AND NOT ZSTD_VALID)
-    MESSAGE(FATAL_ERROR
-      "WITH_ROCKSDB_ZSTD is ON and ZSTD library was found, but the version needs to be >= 1.1.3")
-  endif()
   if (ZSTD_VALID)
     set(HAVE_ROCKSDB_ZSTD TRUE)
     add_definitions(-DZSTD)
