--- xf86drm.c.orig	2021-01-11 18:15:27 UTC
+++ xf86drm.c
@@ -62,7 +62,17 @@
 #endif
 #include <math.h>
 
-#if defined(__FreeBSD__)
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#define FREEDFLY 1
+#else
+#define FREEDFLY 0
+#endif
+
+#if FREEDFLY
 #include <sys/param.h>
 #include <sys/pciio.h>
 #endif
@@ -540,7 +550,7 @@ static int drmGetMinorBase(int type)
 
 static int drmGetMinorType(int major, int minor)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     char name[SPECNAMELEN];
     int id;
 
@@ -2791,7 +2801,7 @@ drm_public int drmIsMaster(int fd)
 
 drm_public char *drmGetDeviceNameFromFd(int fd)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     struct stat sbuf;
     int maj, min;
     int nodetype;
@@ -2838,7 +2848,7 @@ static bool drmNodeIsDRM(int maj, int mi
     snprintf(path, sizeof(path), "/sys/dev/char/%d:%d/device/drm",
              maj, min);
     return stat(path, &sbuf) == 0;
-#elif defined(__FreeBSD__)
+#elif FREEDFLY
     char name[SPECNAMELEN];
 
     if (!devname_r(makedev(maj, min), S_IFCHR, name, sizeof(name)))
@@ -2951,7 +2961,7 @@ static char *drmGetMinorNameForFD(int fd
 
     closedir(sysdir);
     return NULL;
-#elif defined(__FreeBSD__)
+#elif FREEDFLY
     struct stat sbuf;
     char dname[SPECNAMELEN];
     const char *mname;
@@ -3162,7 +3172,7 @@ get_pci_path(int maj, int min, char *pci
 }
 #endif
 
-#ifdef __FreeBSD__
+#if FREEDFLY
 static int get_sysctl_pci_bus_info(int maj, int min, drmPciBusInfoPtr info)
 {
     char dname[SPECNAMELEN];
