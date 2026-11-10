--- tclconfig/tcl.m4.orig	2026-11-09 20:14:22 UTC
+++ tclconfig/tcl.m4
@@ -1628,26 +1628,21 @@ dnl AC_CHECK_TOOL(AR, ar)
 		;;
 	    esac
 	    ;;
-	FreeBSD-*)
+	FreeBSD-*|DragonFly-*|MidnightBSD-*)
 	    # This configuration from FreeBSD Ports.
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_LD="${CC} -shared"
-	    TCL_SHLIB_LD_EXTRAS="-soname \$[@]"
+	    SHLIB_LD_LIBS="${SHLIB_LD_LIBS} -Wl,-soname,libexpect.so.1"
 	    SHLIB_SUFFIX=".so"
 	    LDFLAGS=""
 	    AS_IF([test $doRpath = yes], [
 		CC_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'
-		LD_SEARCH_FLAGS='-rpath ${LIB_RUNTIME_DIR}'])
+	        LD_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'])
 	    AS_IF([test "${TCL_THREADS}" = "1"], [
 		# The -pthread needs to go in the LDFLAGS, not LIBS
 		LIBS=`echo $LIBS | sed s/-pthread//`
 		CFLAGS="$CFLAGS $PTHREAD_CFLAGS"
 		LDFLAGS="$LDFLAGS $PTHREAD_LIBS"])
-	    # Version numbers are dot-stripped by system policy.
-	    TCL_TRIM_DOTS=`echo ${VERSION} | tr -d .`
-	    UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
-	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so.1'
-	    TCL_LIB_VERSIONS_OK=nodots
 	    ;;
 	Darwin-*)
 	    CFLAGS_OPTIMIZE="-Os"
@@ -1968,7 +1963,7 @@ dnl # preprocessing tests use only CPPFL
 	    BSD/OS*) ;;
 	    CYGWIN_*) ;;
 	    IRIX*) ;;
-	    NetBSD-*|FreeBSD-*|OpenBSD-*) ;;
+	    NetBSD-*|FreeBSD-*|OpenBSD-*|DragonFly-*|MidnightBSD-*) ;;
 	    Darwin-*) ;;
 	    SCO_SV-3.2*) ;;
 	    windows) ;;
