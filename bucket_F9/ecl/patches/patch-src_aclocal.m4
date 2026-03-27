--- src/aclocal.m4.orig	2026-03-27 08:12:03 UTC
+++ src/aclocal.m4
@@ -354,7 +354,7 @@ case "${host_os}" in
                 ECL_ADD_FEATURE([unix])
                 ECL_ADD_FEATURE([bsd])
                 ;;
-        freebsd*)
+        freebsd*|midnight*)
                 thehost='freebsd'
                 THREAD_LIBS='-lpthread'
                 SHARED_LDFLAGS="-shared ${LDFLAGS}"
