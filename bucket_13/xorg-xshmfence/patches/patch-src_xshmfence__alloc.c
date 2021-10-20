--- src/xshmfence_alloc.c.orig	2018-02-26 17:26:59 UTC
+++ src/xshmfence_alloc.c
@@ -67,15 +67,19 @@ int
 xshmfence_alloc_shm(void)
 {
 	char	template[] = SHMDIR "/shmfd-XXXXXX";
-	int	fd;
+	int	fd = -1;
 
 #if HAVE_MEMFD_CREATE
 	fd = memfd_create("xshmfence", MFD_CLOEXEC|MFD_ALLOW_SEALING);
 	if (fd < 0)
 #endif
 	{
-#ifdef O_TMPFILE
+#if defined(O_CLOEXEC)
+#if defined(HAVE_MKOSTEMP)
+		fd = mkostemp(template, O_CLOEXEC);
+#elif defined(O_TMPFILE)
 		fd = open(SHMDIR, O_TMPFILE|O_RDWR|O_CLOEXEC|O_EXCL, 0666);
+#endif
 		if (fd < 0)
 #endif
 		{
@@ -110,6 +114,9 @@ xshmfence_map_shm(int fd)
 		close (fd);
 		return 0;
 	}
+#ifdef HAVE_SEMAPHORE
+	xshmfence_open_semaphore(addr);
+#endif
 	return addr;
 }
 
@@ -121,5 +128,8 @@ xshmfence_map_shm(int fd)
 void
 xshmfence_unmap_shm(struct xshmfence *f)
 {
+#ifdef HAVE_SEMAPHORE
+	xshmfence_close_semaphore(f);
+#endif
         munmap(f, sizeof (struct xshmfence));
 }
