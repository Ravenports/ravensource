--- generate_install_sh.sh.orig	2025-09-25 16:14:00 UTC
+++ generate_install_sh.sh
@@ -1,7 +1,7 @@
 #!/usr/bin/env bash
 
 
-INSTALLPREFIX=`cat compileoptions.h |grep INSTALL_PREFIX|cut -d '"' -f2`
+INSTALLPREFIX=__PREFIX__
 EDITION_NAME_GAME=`cat cpu.h|grep EDITION_NAME_GAME|cut -d '"' -f2`
 
 
