--- /dev/null	2025-04-25 23:43:36 UTC
+++ boost/predef/os/bsd/midnight.h
@@ -0,0 +1,59 @@
+/*
+Copyright Rene Rivera 2012-2015
+Distributed under the Boost Software License, Version 1.0.
+(See accompanying file LICENSE_1_0.txt or copy at
+http://www.boost.org/LICENSE_1_0.txt)
+*/
+
+#ifndef BOOST_PREDEF_OS_BSD_FREE_H
+#define BOOST_PREDEF_OS_BSD_FREE_H
+
+#include <boost/predef/os/bsd.h>
+
+/* tag::reference[]
+= `BOOST_OS_BSD_MIDNIGHT`
+
+http://en.wikipedia.org/wiki/Midnightbsd[MidnightBSD] operating system.
+
+[options="header"]
+|===
+| {predef_symbol} | {predef_version}
+
+| `+__MidnightBSD__+` | {predef_detection}
+
+| `+__MidnightBSD_version+` | V.R.P
+|===
+*/ // end::reference[]
+
+#define BOOST_OS_BSD_MIDNIGHT BOOST_VERSION_NUMBER_NOT_AVAILABLE
+
+#if !defined(BOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
+    defined(__MidnightBSD__) \
+    )
+#   ifndef BOOST_OS_BSD_AVAILABLE
+#       undef BOOST_OS_BSD
+#       define BOOST_OS_BSD BOOST_VERSION_NUMBER_AVAILABLE
+#       define BOOST_OS_BSD_AVAILABLE
+#   endif
+#   undef BOOST_OS_BSD_FREE
+#   include <sys/param.h>
+#   if defined(__MidnightBSD_version)
+#           define BOOST_OS_BSD_MIDNIGHT \
+                BOOST_PREDEF_MAKE_10_VVRRPPP(__MidnightBSD_version)
+
+#   else
+#       define BOOST_OS_BSD_MIDNIGHT BOOST_VERSION_NUMBER_AVAILABLE
+#   endif
+#endif
+
+#if BOOST_OS_BSD_MIDNIGHT
+#   define BOOST_OS_BSD_MIDNIGHT_AVAILABLE
+#   include <boost/predef/detail/os_detected.h>
+#endif
+
+#define BOOST_OS_BSD_MIDNIGHT_NAME "Midnight BSD"
+
+#endif
+
+#include <boost/predef/detail/test.h>
+BOOST_PREDEF_DECLARE_TEST(BOOST_OS_BSD_MIDNIGHT,BOOST_OS_BSD_MIDNIGHT_NAME)
