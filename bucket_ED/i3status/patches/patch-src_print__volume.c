--- src/print_volume.c.orig	2021-11-09 07:27:11 UTC
+++ src/print_volume.c
@@ -243,7 +243,7 @@ void print_volume(volume_ctx_t *ctx) {
     goto out_with_format;
 
 #endif
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     char *mixerpath;
     char defaultmixer[] = "/dev/mixer";
     int mixfd, vol, devmask = 0;
