--- src/cdrom/freebsd/SDL_syscdrom.c.orig	2012-01-19 06:30:06 UTC
+++ src/cdrom/freebsd/SDL_syscdrom.c
@@ -188,7 +188,7 @@ int  SDL_SYS_CDInit(void)
 			char *insert;
 			exists = 1;
 			for ( j=checklist[i][1]; exists; ++j ) {
-				SDL_snprintf(drive, SDL_arraysize(drive), "/dev/%sc", &checklist[i][3]);
+				SDL_snprintf(drive, SDL_arraysize(drive), "/dev/%s", &checklist[i][3]);
 				insert = SDL_strchr(drive, '?');
 				if ( insert != NULL ) {
 					*insert = j;
