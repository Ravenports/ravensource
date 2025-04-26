--- boost/predef/os/bsd.h.orig	2025-04-03 11:37:29 UTC
+++ boost/predef/os/bsd.h
@@ -29,6 +29,7 @@ version number macro to match:
 
 * `BOOST_OS_BSD_DRAGONFLY` http://en.wikipedia.org/wiki/DragonFly_BSD[DragonFly BSD]
 * `BOOST_OS_BSD_FREE` http://en.wikipedia.org/wiki/Freebsd[FreeBSD]
+* `BOOST_OS_BSD_MIDNIGHT` http://en.wikipedia.org/wiki/Midnightbsd[MidnightBSD]
 * `BOOST_OS_BSD_BSDI` http://en.wikipedia.org/wiki/BSD/OS[BSDi BSD/OS]
 * `BOOST_OS_BSD_NET` http://en.wikipedia.org/wiki/Netbsd[NetBSD]
 * `BOOST_OS_BSD_OPEN` http://en.wikipedia.org/wiki/Openbsd[OpenBSD]
@@ -53,6 +54,7 @@ of BSD. If the above variants is detecte
 #include <boost/predef/os/bsd/bsdi.h>
 #include <boost/predef/os/bsd/dragonfly.h>
 #include <boost/predef/os/bsd/free.h>
+#include <boost/predef/os/bsd/midnight.h>
 #include <boost/predef/os/bsd/open.h>
 #include <boost/predef/os/bsd/net.h>
 
@@ -95,6 +97,7 @@ of BSD. If the above variants is detecte
 #include <boost/predef/os/bsd/bsdi.h>
 #include <boost/predef/os/bsd/dragonfly.h>
 #include <boost/predef/os/bsd/free.h>
+#include <boost/predef/os/bsd/midnight.h>
 #include <boost/predef/os/bsd/open.h>
 #include <boost/predef/os/bsd/net.h>
 
