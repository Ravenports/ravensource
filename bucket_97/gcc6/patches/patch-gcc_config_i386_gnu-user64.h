--- gcc/config/i386/gnu-user64.h.orig	2016-01-04 08:30:50.000000000 -0600
+++ gcc/config/i386/gnu-user64.h	2017-05-19 15:55:41.756608223 -0500
@@ -57,6 +57,7 @@
                    %{" SPEC_32 ":-m " GNU_USER_LINK_EMULATION32 "} \
                    %{" SPEC_X32 ":-m " GNU_USER_LINK_EMULATIONX32 "} \
   %{shared:-shared} \
+  %{!static:--enable-new-dtags -rpath @PREFIX@/@GCCAUX@/lib64} \
   %{!shared: \
     %{!static: \
       %{rdynamic:-export-dynamic} \
