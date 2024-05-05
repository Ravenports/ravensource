--- src/aclocal.m4.orig	2023-09-08 16:55:48 UTC
+++ src/aclocal.m4
@@ -335,7 +335,7 @@ case "${host_os}" in
                 SONAME="${SHAREDPREFIX}ecl.${SHAREDEXT}.SOVERSION"
                 SONAME_LDFLAGS="-Wl,-soname,SONAME"
                 ;;
-        freebsd*)
+        freebsd*|midnight*)
                 thehost='freebsd'
                 THREAD_LIBS='-lpthread'
                 SHARED_LDFLAGS="-shared ${LDFLAGS}"
