--- crypto/compat/getentropy_solaris.c.orig	2018-12-15 16:56:31 UTC
+++ crypto/compat/getentropy_solaris.c
@@ -43,9 +43,6 @@
 #include <unistd.h>
 #include <time.h>
 #include <sys/sha2.h>
-#define SHA512_Init SHA512Init
-#define SHA512_Update SHA512Update
-#define SHA512_Final SHA512Final
 
 #include <sys/vfs.h>
 #include <sys/statfs.h>
@@ -66,12 +63,9 @@
 #define HD(x)	 (SHA512_Update(&ctx, (char *)&(x), sizeof (x)))
 #define HF(x)    (SHA512_Update(&ctx, (char *)&(x), sizeof (void*)))
 
-int	getentropy(void *buf, size_t len);
 
 static int getentropy_urandom(void *buf, size_t len, const char *path,
     int devfscheck);
-static int getentropy_fallback(void *buf, size_t len);
-static int getentropy_phdr(struct dl_phdr_info *info, size_t size, void *data);
 
 int
 getentropy(void *buf, size_t len)
@@ -95,7 +89,7 @@ getentropy(void *buf, size_t len)
 	 * the devfs mount, or if file descriptors are exhausted.
 	 */
 	ret = getentropy_urandom(buf, len,
-	    "/devices/pseudo/random@0:urandom", 1);
+	    "/devices/pseudo/random@0:urandom", 0);
 	if (ret != -1)
 		return (ret);
 
@@ -135,16 +129,8 @@ getentropy(void *buf, size_t len)
 	 * providing a new failsafe API which works in a chroot or
 	 * when file descriptors are exhausted.
 	 */
-#undef FAIL_INSTEAD_OF_TRYING_FALLBACK
-#ifdef FAIL_INSTEAD_OF_TRYING_FALLBACK
-	raise(SIGKILL);
-#endif
-	ret = getentropy_fallback(buf, len);
-	if (ret != -1)
-		return (ret);
-
-	errno = EIO;
-	return (ret);
+	printf("Collecting entropy via /dev/urandom has failed.\n");
+	return (-1);
 }
 
 static int
@@ -224,199 +210,3 @@ static const int cl[] = {
 	CLOCK_THREAD_CPUTIME_ID,
 #endif
 };
-
-static int
-getentropy_phdr(struct dl_phdr_info *info, size_t size, void *data)
-{
-	SHA512_CTX *ctx = data;
-
-	SHA512_Update(ctx, &info->dlpi_addr, sizeof (info->dlpi_addr));
-	return (0);
-}
-
-static int
-getentropy_fallback(void *buf, size_t len)
-{
-	uint8_t results[SHA512_DIGEST_LENGTH];
-	int save_errno = errno, e, pgs = getpagesize(), faster = 0, repeat;
-	static int cnt;
-	struct timespec ts;
-	struct timeval tv;
-	double loadavg[3];
-	struct rusage ru;
-	sigset_t sigset;
-	struct stat st;
-	SHA512_CTX ctx;
-	static pid_t lastpid;
-	pid_t pid;
-	size_t i, ii, m;
-	char *p;
-
-	pid = getpid();
-	if (lastpid == pid) {
-		faster = 1;
-		repeat = 2;
-	} else {
-		faster = 0;
-		lastpid = pid;
-		repeat = REPEAT;
-	}
-	for (i = 0; i < len; ) {
-		int j;
-		SHA512_Init(&ctx);
-		for (j = 0; j < repeat; j++) {
-			HX((e = gettimeofday(&tv, NULL)) == -1, tv);
-			if (e != -1) {
-				cnt += (int)tv.tv_sec;
-				cnt += (int)tv.tv_usec;
-			}
-
-			dl_iterate_phdr(getentropy_phdr, &ctx);
-
-			for (ii = 0; ii < sizeof(cl)/sizeof(cl[0]); ii++)
-				HX(clock_gettime(cl[ii], &ts) == -1, ts);
-
-			HX((pid = getpid()) == -1, pid);
-			HX((pid = getsid(pid)) == -1, pid);
-			HX((pid = getppid()) == -1, pid);
-			HX((pid = getpgid(0)) == -1, pid);
-			HX((e = getpriority(0, 0)) == -1, e);
-			HX((getloadavg(loadavg, 3) == -1), loadavg);
-
-			if (!faster) {
-				ts.tv_sec = 0;
-				ts.tv_nsec = 1;
-				(void) nanosleep(&ts, NULL);
-			}
-
-			HX(sigpending(&sigset) == -1, sigset);
-			HX(sigprocmask(SIG_BLOCK, NULL, &sigset) == -1,
-			    sigset);
-
-			HF(getentropy);	/* an addr in this library */
-			HF(printf);		/* an addr in libc */
-			p = (char *)&p;
-			HD(p);		/* an addr on stack */
-			p = (char *)&errno;
-			HD(p);		/* the addr of errno */
-
-			if (i == 0) {
-				struct sockaddr_storage ss;
-				struct statvfs stvfs;
-				struct termios tios;
-				socklen_t ssl;
-				off_t off;
-
-				/*
-				 * Prime-sized mappings encourage fragmentation;
-				 * thus exposing some address entropy.
-				 */
-				struct mm {
-					size_t	npg;
-					void	*p;
-				} mm[] =	 {
-					{ 17, MAP_FAILED }, { 3, MAP_FAILED },
-					{ 11, MAP_FAILED }, { 2, MAP_FAILED },
-					{ 5, MAP_FAILED }, { 3, MAP_FAILED },
-					{ 7, MAP_FAILED }, { 1, MAP_FAILED },
-					{ 57, MAP_FAILED }, { 3, MAP_FAILED },
-					{ 131, MAP_FAILED }, { 1, MAP_FAILED },
-				};
-
-				for (m = 0; m < sizeof mm/sizeof(mm[0]); m++) {
-					HX(mm[m].p = mmap(NULL,
-					    mm[m].npg * pgs,
-					    PROT_READ|PROT_WRITE,
-					    MAP_PRIVATE|MAP_ANON, -1,
-					    (off_t)0), mm[m].p);
-					if (mm[m].p != MAP_FAILED) {
-						size_t mo;
-
-						/* Touch some memory... */
-						p = mm[m].p;
-						mo = cnt %
-						    (mm[m].npg * pgs - 1);
-						p[mo] = 1;
-						cnt += (int)((long)(mm[m].p)
-						    / pgs);
-					}
-
-					/* Check cnts and times... */
-					for (ii = 0; ii < sizeof(cl)/sizeof(cl[0]);
-					    ii++) {
-						HX((e = clock_gettime(cl[ii],
-						    &ts)) == -1, ts);
-						if (e != -1)
-							cnt += (int)ts.tv_nsec;
-					}
-
-					HX((e = getrusage(RUSAGE_SELF,
-					    &ru)) == -1, ru);
-					if (e != -1) {
-						cnt += (int)ru.ru_utime.tv_sec;
-						cnt += (int)ru.ru_utime.tv_usec;
-					}
-				}
-
-				for (m = 0; m < sizeof mm/sizeof(mm[0]); m++) {
-					if (mm[m].p != MAP_FAILED)
-						munmap(mm[m].p, mm[m].npg * pgs);
-					mm[m].p = MAP_FAILED;
-				}
-
-				HX(stat(".", &st) == -1, st);
-				HX(statvfs(".", &stvfs) == -1, stvfs);
-
-				HX(stat("/", &st) == -1, st);
-				HX(statvfs("/", &stvfs) == -1, stvfs);
-
-				HX((e = fstat(0, &st)) == -1, st);
-				if (e == -1) {
-					if (S_ISREG(st.st_mode) ||
-					    S_ISFIFO(st.st_mode) ||
-					    S_ISSOCK(st.st_mode)) {
-						HX(fstatvfs(0, &stvfs) == -1,
-						    stvfs);
-						HX((off = lseek(0, (off_t)0,
-						    SEEK_CUR)) < 0, off);
-					}
-					if (S_ISCHR(st.st_mode)) {
-						HX(tcgetattr(0, &tios) == -1,
-						    tios);
-					} else if (S_ISSOCK(st.st_mode)) {
-						memset(&ss, 0, sizeof ss);
-						ssl = sizeof(ss);
-						HX(getpeername(0,
-						    (void *)&ss, &ssl) == -1,
-						    ss);
-					}
-				}
-
-				HX((e = getrusage(RUSAGE_CHILDREN,
-				    &ru)) == -1, ru);
-				if (e != -1) {
-					cnt += (int)ru.ru_utime.tv_sec;
-					cnt += (int)ru.ru_utime.tv_usec;
-				}
-			} else {
-				/* Subsequent hashes absorb previous result */
-				HD(results);
-			}
-
-			HX((e = gettimeofday(&tv, NULL)) == -1, tv);
-			if (e != -1) {
-				cnt += (int)tv.tv_sec;
-				cnt += (int)tv.tv_usec;
-			}
-
-			HD(cnt);
-		}
-		SHA512_Final(results, &ctx);
-		memcpy((char *)buf + i, results, min(sizeof(results), len - i));
-		i += min(sizeof(results), len - i);
-	}
-	explicit_bzero(&ctx, sizeof ctx);
-	explicit_bzero(results, sizeof results);
-	errno = save_errno;
-	return (0);		/* satisfied */
-}
