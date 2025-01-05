--- scripts/wsrep_sst_mariabackup.sh.orig	2024-11-11 07:18:44 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -800,8 +800,7 @@ recv_joiner()
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
             local koption=0
-            if [ "$OS" = 'FreeBSD' -o "$OS" = 'NetBSD' -o "$OS" = 'OpenBSD' -o \
-                 "$OS" = 'DragonFly' ]; then
+            if [ 1 eq 1 ]; then
                 if timeout 2>&1 | grep -qw -F -- '-k'; then
                     koption=1
                 fi
