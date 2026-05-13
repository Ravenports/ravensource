--- m4/nut_check_libltdl.m4.orig	2026-03-02 10:26:11 UTC
+++ m4/nut_check_libltdl.m4
@@ -10,9 +10,6 @@ if test -z "${nut_have_libltdl_seen}"; t
 	dnl No NUT_CHECK_PKGCONFIG here: (lib)ltdl.pc was not seen on any OS
 
 	dnl save CFLAGS and LIBS
-	CFLAGS_ORIG="${CFLAGS}"
-	LIBS_ORIG="${LIBS}"
-	CFLAGS=""
 	LIBS=""
 	depCFLAGS=""
 	depCFLAGS_SOURCE=""
@@ -89,7 +86,5 @@ if test -z "${nut_have_libltdl_seen}"; t
 	unset depLIBS_SOURCE
 
 	dnl restore original CFLAGS and LIBS
-	CFLAGS="${CFLAGS_ORIG}"
-	LIBS="${LIBS_ORIG}"
 fi
 ])
