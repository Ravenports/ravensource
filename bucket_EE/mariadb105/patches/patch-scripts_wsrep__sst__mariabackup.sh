--- scripts/wsrep_sst_mariabackup.sh.orig	2024-01-31 16:38:21 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -803,7 +803,7 @@ recv_joiner()
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
             local koption=0
-            if [ "$OS" = 'FreeBSD' ]; then
+            if [ 1 eq 1 ]; then
                 if timeout 2>&1 | grep -qw -F -- '-k'; then
                     koption=1
                 fi
