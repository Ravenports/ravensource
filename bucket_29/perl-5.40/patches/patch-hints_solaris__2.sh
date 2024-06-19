--- hints/solaris_2.sh.orig	2024-04-16 17:11:38 UTC
+++ hints/solaris_2.sh
@@ -20,6 +20,9 @@
 #  gcc will occasionally emit warnings about "unused prefix", but
 #  these ought to be harmless.  See below for more details.
 
+lddlflags="-shared "
+cccdlflags='-DPIC -fPIC'
+
 # Solaris has secure SUID scripts
 d_suidsafe=${d_suidsafe:-define}
 
