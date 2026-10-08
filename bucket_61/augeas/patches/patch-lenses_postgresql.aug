--- lenses/postgresql.aug.orig	2026-09-29 22:03:14 UTC
+++ lenses/postgresql.aug
@@ -70,6 +70,7 @@ let lns = (Util.empty | Util.comment | e
 
 (* Variable: filter *)
 let filter = (incl "/var/lib/pgsql/data/postgresql.conf" .
+              incl "%%PREFIX%%/pgsql/data/postgresql.conf" .
               incl "/usr/local/pgsql/data/postgresql.conf" .
               incl "/var/lib/pgsql/*/data/postgresql.conf" .
               incl "/var/lib/postgresql/*/data/postgresql.conf" .
