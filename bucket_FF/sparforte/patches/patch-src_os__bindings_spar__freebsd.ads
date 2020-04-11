--- src/os_bindings/spar_freebsd.ads.orig	2020-03-28 23:21:57 UTC
+++ src/os_bindings/spar_freebsd.ads
@@ -653,7 +653,7 @@ pragma import( C, C_is_includable_file,
 --  True if a file exists, is readable, not world writable and has data
 -- (that is, that it has permissions for an include file)
 
-function C_is_secure_dir( char * path ) return boolean;
+function C_is_secure_dir( path : string ) return boolean;
 pragma import( C, C_is_secure_dir, "C_is_secure_dir" );
 --  True if a dir exists, is readable, not world writable.
 
