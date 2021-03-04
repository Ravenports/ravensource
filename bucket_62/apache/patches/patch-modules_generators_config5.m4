--- modules/generators/config5.m4.orig	2011-11-12 00:21:04 UTC
+++ modules/generators/config5.m4
@@ -51,8 +51,7 @@ if test $cgid_needed = "yes"; then
               ;;
           esac
           AC_MSG_CHECKING([for Solaris patch $patch_id])
-          showrev -p | grep "$patch_id" >/dev/null 2>&1
-          if test $? -eq 1; then
+          if test 0 -eq 1; then
           dnl Solaris 11 (next release) as of snv_19 doesn't have this problem.
           dnl It may be possible to use /kernel/drv/tl from later releases.
           AC_MSG_ERROR([Please apply either patch # 120664 (Sparc) or # 120665 (x86).
