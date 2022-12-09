--- src/xshmfence_alloc.c.orig	2022-12-08 16:08:26 UTC
+++ src/xshmfence_alloc.c
@@ -69,7 +69,7 @@ int
 xshmfence_alloc_shm(void)
 {
 	char	template[] = SHMDIR "/shmfd-XXXXXX";
-	int	fd;
+	int	fd = -1;
 #ifndef HAVE_MKOSTEMP
 	int	flags;
 #endif
@@ -130,6 +130,9 @@ xshmfence_map_shm(int fd)
 		close (fd);
 		return 0;
 	}
+#ifdef HAVE_SEMAPHORE
+	xshmfence_open_semaphore(addr);
+#endif
 	return addr;
 }
 
@@ -141,5 +144,8 @@ xshmfence_map_shm(int fd)
 void
 xshmfence_unmap_shm(struct xshmfence *f)
 {
+#ifdef HAVE_SEMAPHORE
+	xshmfence_close_semaphore(f);
+#endif
         munmap(f, sizeof (struct xshmfence));
 }
