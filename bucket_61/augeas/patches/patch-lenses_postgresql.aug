--- lenses/postgresql.aug.orig	2023-07-14 11:07:23 UTC
+++ lenses/postgresql.aug
@@ -70,6 +70,7 @@ let lns = (Util.empty | Util.comment | e
 
 (* Variable: filter *)
 let filter = (incl "/var/lib/pgsql/data/postgresql.conf" .
+              incl "%%PREFIX%%/pgsql/data/postgresql.conf" .
               incl "/var/lib/pgsql/*/data/postgresql.conf" .
               incl "/var/lib/postgresql/*/data/postgresql.conf" .
               incl "/etc/postgresql/*/*/postgresql.conf" )
