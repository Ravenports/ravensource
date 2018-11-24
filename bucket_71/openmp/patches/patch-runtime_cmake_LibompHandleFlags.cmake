--- runtime/cmake/LibompHandleFlags.cmake.orig	2018-07-30 18:16:22 UTC
+++ runtime/cmake/LibompHandleFlags.cmake
@@ -153,9 +153,9 @@ function(libomp_get_libflags libflags)
   if(${IA32})
     libomp_append(libflags_local -lirc_pic LIBOMP_HAVE_IRC_PIC_LIBRARY)
   endif()
-  IF(${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
+  IF(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD|DragonFly|NetBSD")
     libomp_append(libflags_local -lm)
-  ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
+  ENDIF()
   set(libflags_local ${libflags_local} ${LIBOMP_LIBFLAGS})
   libomp_setup_flags(libflags_local)
   set(${libflags} ${libflags_local} PARENT_SCOPE)
