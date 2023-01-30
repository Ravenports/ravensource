--- aclocal.m4.orig	2021-10-17 15:16:03 UTC
+++ aclocal.m4
@@ -2246,7 +2246,7 @@ then
 		LD_RPATH_OPT="-Wl,-rpath,"
 		;;
 	(dragonfly*)
-		LD_RPATH_OPT="-rpath "
+		LD_RPATH_OPT="-Wl,-rpath,"
 		;;
 	(netbsd*)
 		LD_RPATH_OPT="-Wl,-rpath,"
@@ -2255,7 +2255,7 @@ then
 		LD_RPATH_OPT="-rpath "
 		;;
 	(solaris2*)
-		LD_RPATH_OPT="-R"
+		LD_RPATH_OPT="-Wl,-R"
 		;;
 	(*)
 		;;
@@ -2777,7 +2777,7 @@ AC_ARG_ENABLE(widec,
 AC_MSG_RESULT($with_widec)
 if test "$with_widec" = yes ; then
 	CF_UTF8_LIB
-	CF_NCURSES_CONFIG(ncursesw)
+	CF_NCURSES_CONFIG(ncurses)
 else
 	CF_NCURSES_CONFIG(ncurses)
 fi
@@ -4281,11 +4281,11 @@ CF_EOF
 		# tested with SunOS 5.5.1 (solaris 2.5.1) and gcc 2.7.2
 		# tested with SunOS 5.10 (solaris 10) and gcc 3.4.3
 		if test "$DFT_LWR_MODEL" = "shared" ; then
-			LOCAL_LDFLAGS="-R \$(LOCAL_LIBDIR):\${libdir}"
+			LOCAL_LDFLAGS="-Wl,-R \$(LOCAL_LIBDIR):\${libdir}"
 			LOCAL_LDFLAGS2="$LOCAL_LDFLAGS"
 		fi
 		if test "$cf_cv_enable_rpath" = yes ; then
-			EXTRA_LDFLAGS="-R \${libdir} $EXTRA_LDFLAGS"
+			EXTRA_LDFLAGS="-Wl,-R \${libdir} $EXTRA_LDFLAGS"
 		fi
 		CF_SHARED_SONAME
 		if test "$GCC" != yes; then
