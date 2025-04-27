--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cpp.orig	2025-04-16 00:23:49 UTC
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cpp
@@ -47,7 +47,6 @@
 #include <sys/ioctl_compat.h>
 #include <sys/joystick.h>
 #include <sys/ksyms.h>
-#include <sys/lua.h>
 #include <sys/midiio.h>
 #include <sys/mtio.h>
 #include <sys/power.h>
@@ -493,12 +492,7 @@ struct urio_command {
 #include <semaphore.h>
 #include <signal.h>
 #include <stddef.h>
-#include <md2.h>
-#include <md4.h>
-#include <md5.h>
-#include <rmd160.h>
 #include <soundcard.h>
-#include <term.h>
 #include <termios.h>
 #include <time.h>
 #include <ttyent.h>
@@ -514,9 +508,6 @@ struct urio_command {
 #include <fstab.h>
 #include <stringlist.h>
 
-#if defined(__x86_64__)
-#include <nvmm.h>
-#endif
 // clang-format on
 
 // Include these after system headers to avoid name clashes and ambiguities.
