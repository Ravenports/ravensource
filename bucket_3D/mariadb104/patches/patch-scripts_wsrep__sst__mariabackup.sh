--- scripts/wsrep_sst_mariabackup.sh.orig	2024-05-06 15:18:46 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -800,7 +800,7 @@ recv_joiner()
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
             local koption=0
-            if [ "$OS" = 'FreeBSD' ]; then
+            if [ 1 eq 1 ]; then
                 if timeout 2>&1 | grep -qw -F -- '-k'; then
                     koption=1
                 fi
