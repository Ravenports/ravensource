--- gcc/config/sol2.h.orig	2016-01-04 14:30:50 UTC
+++ gcc/config/sol2.h
@@ -334,6 +334,7 @@ along with GCC; see the file COPYING3.
    %{static:-dn -Bstatic} \
    %{shared:-G -dy %{!mimpure-text:-z text}} " \
    LINK_LIBGCC_MAPFILE_SPEC LINK_CLEARCAP_SPEC " \
+   %{!static:-R/lib/amd64:@PREFIX@/@GCCAUX@/lib/amd64} \
    %{symbolic:-Bsymbolic -G -dy -z text} \
    %(link_arch) \
    %{Qy:} %{!Qn:-Qy}"
