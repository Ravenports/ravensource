--- Makefile.SH.orig	2019-04-02 20:36:35 UTC
+++ Makefile.SH
@@ -40,7 +40,6 @@ esac
 pwd="`pwd`"
 linklibperl='$(LIBPERL)'
 linklibperl_nonshr=''
-shrpldflags='$(LDDLFLAGS)'
 ldlibpth=''
 DPERL_EXTERNAL_GLOB='-DPERL_EXTERNAL_GLOB'
 DPERL_IS_MINIPERL='-DPERL_IS_MINIPERL'
