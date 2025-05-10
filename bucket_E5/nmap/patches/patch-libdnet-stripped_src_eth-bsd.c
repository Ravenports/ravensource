--- libdnet-stripped/src/eth-bsd.c.orig	2025-03-31 19:30:47 UTC
+++ libdnet-stripped/src/eth-bsd.c
@@ -45,7 +45,7 @@ eth_open(const char *device)
 
 	if ((e = calloc(1, sizeof(*e))) != NULL) {
 		char file[32] = "/dev/bpf";
-		for (i = 0; i <= 128; i++) {
+		for (i = 0; i <= 1024; i++) {
 			/* This would be O_WRONLY, but Mac OS X 10.6 has a bug
 			   where that prevents other users of the interface
 			   from seeing incoming traffic, even in other
