--- hints/solaris_2.sh.orig	2025-03-30 10:35:50 UTC
+++ hints/solaris_2.sh
@@ -20,6 +20,9 @@
 #  gcc will occasionally emit warnings about "unused prefix", but
 #  these ought to be harmless.  See below for more details.
 
+lddlflags="-shared "
+cccdlflags='-DPIC -fPIC'
+
 # Solaris has secure SUID scripts
 d_suidsafe=${d_suidsafe:-define}
 
