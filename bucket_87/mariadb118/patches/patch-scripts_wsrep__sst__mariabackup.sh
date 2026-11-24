--- scripts/wsrep_sst_mariabackup.sh.orig	2026-11-09 19:49:48 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -899,8 +899,7 @@ recv_joiner()
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
             local koption=0
-            if [ "$OS" = 'FreeBSD' -o "$OS" = 'NetBSD' -o "$OS" = 'OpenBSD' -o \
-                 "$OS" = 'DragonFly' ]; then
+            if [ 1 eq 1 ]; then
                 if timeout 2>&1 | grep -qw -F -- '-k'; then
                     koption=1
                 fi
