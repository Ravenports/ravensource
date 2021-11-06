EBADFD is not specified in POSIX, EBADF is.

--- lib/glue/unix.cpp.orig	2021-10-19 09:51:29 UTC
+++ lib/glue/unix.cpp
@@ -87,7 +87,7 @@ int send_fd(int socket, fz::buffer & buf
 		return -1;
 	}
 	if (socket < 0) {
-		error = EBADFD;
+		error = EBADF;
 		return -1;
 	}
 
@@ -144,7 +144,7 @@ int read_fd(int socket, fz::buffer & buf
 {
 	fd = -1;
 	if (socket < 0) {
-		error = EBADFD;
+		error = EBADF;
 		return -1;
 	}
 
