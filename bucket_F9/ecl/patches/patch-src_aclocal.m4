--- src/aclocal.m4.orig	2024-05-10 11:13:55 UTC
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
