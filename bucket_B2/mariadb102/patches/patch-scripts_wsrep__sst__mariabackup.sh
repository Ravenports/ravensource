--- scripts/wsrep_sst_mariabackup.sh.orig	2022-05-18 11:19:09 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -722,7 +722,7 @@ recv_joiner()
     local ltcmd="$tcmd"
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
-            if timeout --help | grep -qw -- '-k'; then
+            if timeout --help 2>&1 | grep -qw -- '-k'; then
                 ltcmd="timeout -k $(( tmt+10 )) $tmt $tcmd"
             else
                 ltcmd="timeout -s9 $tmt $tcmd"
