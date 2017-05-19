--- gcc/config/i386/gnu-user64.h.orig	2016-01-04 08:30:50.000000000 -0600
+++ gcc/config/i386/gnu-user64.h	2017-05-19 09:16:28.204939715 -0500
@@ -59,6 +59,8 @@
   %{shared:-shared} \
   %{!shared: \
     %{!static: \
+      --enable-new-dtags \
+      -rpath @PREFIX@/@GCCAUX@/lib \
       %{rdynamic:-export-dynamic} \
       %{" SPEC_32 ":-dynamic-linker " GNU_USER_DYNAMIC_LINKER32 "} \
       %{" SPEC_64 ":-dynamic-linker " GNU_USER_DYNAMIC_LINKER64 "} \
