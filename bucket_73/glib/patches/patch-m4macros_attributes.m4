--- m4macros/attributes.m4.orig	2021-03-18 13:47:48 UTC
+++ m4macros/attributes.m4
@@ -86,7 +86,7 @@ AC_DEFUN([CC_NOUNDEFINED], [
      dnl FreeBSD (et al.) does not complete linking for shared objects when pthreads
      dnl are requested, as different implementations are present; to avoid problems
      dnl use -Wl,-z,defs only for those platform not behaving this way.
-     *-freebsd* | *-openbsd*) ;;
+     *-freebsd* | *-openbsd* | *-dragonfly*) ;;
      *)
         dnl First of all check for the --no-undefined variant of GNU ld. This allows
         dnl for a much more readable commandline, so that people can understand what
