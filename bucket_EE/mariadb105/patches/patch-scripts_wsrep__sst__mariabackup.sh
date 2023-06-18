--- scripts/wsrep_sst_mariabackup.sh.orig	2023-06-05 16:27:59 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -798,7 +798,7 @@ recv_joiner()
     local ltcmd="$tcmd"
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
-            if timeout --help | grep -qw -F -- '-k'; then
+            if timeout --help 2>&1 | grep -qw -F -- '-k'; then
                 ltcmd="timeout -k $(( tmt+10 )) $tmt $tcmd"
             else
                 ltcmd="timeout -s9 $tmt $tcmd"
