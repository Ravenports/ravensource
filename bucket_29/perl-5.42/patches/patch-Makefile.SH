--- Makefile.SH.orig	2025-06-24 15:23:20 UTC
+++ Makefile.SH
@@ -40,7 +40,6 @@ esac
 pwd="`pwd`"
 linklibperl='$(LIBPERL)'
 linklibperl_nonshr=''
-shrpldflags='$(LDDLFLAGS)'
 ldlibpth=''
 DPERL_EXTERNAL_GLOB='-DPERL_EXTERNAL_GLOB'
 DPERL_IS_MINIPERL='-DPERL_IS_MINIPERL'
