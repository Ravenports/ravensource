--- scripts/wsrep_sst_mariabackup.sh.orig	2023-02-06 19:55:28 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -795,7 +795,7 @@ recv_joiner()
     local ltcmd="$tcmd"
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
-            if timeout --help | grep -qw -F -- '-k'; then
+            if timeout --help 2>&1 | grep -qw -F -- '-k'; then
                 ltcmd="timeout -k $(( tmt+10 )) $tmt $tcmd"
             else
                 ltcmd="timeout -s9 $tmt $tcmd"
