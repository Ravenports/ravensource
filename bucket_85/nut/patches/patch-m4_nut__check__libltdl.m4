--- m4/nut_check_libltdl.m4.orig	2025-04-19 15:08:33 UTC
+++ m4/nut_check_libltdl.m4
@@ -10,10 +10,7 @@ if test -z "${nut_have_libltdl_seen}"; t
 	dnl No NUT_CHECK_PKGCONFIG here: (lib)ltdl.pc was not seen on any OS
 
 	dnl save CFLAGS and LIBS
-	CFLAGS_ORIG="${CFLAGS}"
-	LIBS_ORIG="${LIBS}"
 	LIBS=""
-	CFLAGS=""
 	depLIBS=""
 	depCFLAGS=""
 	dnl For fallback below:
@@ -94,7 +91,5 @@ if test -z "${nut_have_libltdl_seen}"; t
 	unset depLIBS
 
 	dnl restore original CFLAGS and LIBS
-	CFLAGS="${CFLAGS_ORIG}"
-	LIBS="${LIBS_ORIG}"
 fi
 ])
