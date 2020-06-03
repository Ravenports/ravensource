--- xf86drm.c.orig	2020-05-26 20:37:16 UTC
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
@@ -524,7 +534,7 @@ static int drmGetMinorBase(int type)
 
 static int drmGetMinorType(int major, int minor)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     char name[SPECNAMELEN];
     int id;
 
@@ -2775,7 +2785,7 @@ drm_public int drmIsMaster(int fd)
 
 drm_public char *drmGetDeviceNameFromFd(int fd)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     struct stat sbuf;
     int maj, min;
     int nodetype;
@@ -2822,7 +2832,7 @@ static bool drmNodeIsDRM(int maj, int mi
     snprintf(path, sizeof(path), "/sys/dev/char/%d:%d/device/drm",
              maj, min);
     return stat(path, &sbuf) == 0;
-#elif __FreeBSD__
+#elif FREEDFLY
     char name[SPECNAMELEN];
 
     if (!devname_r(makedev(maj, min), S_IFCHR, name, sizeof(name)))
@@ -2935,7 +2945,7 @@ static char *drmGetMinorNameForFD(int fd
 
     closedir(sysdir);
     return NULL;
-#elif __FreeBSD__
+#elif FREEDFLY
     struct stat sbuf;
     char dname[SPECNAMELEN];
     const char *mname;
@@ -3146,7 +3156,7 @@ get_pci_path(int maj, int min, char *pci
 }
 #endif
 
-#ifdef __FreeBSD__
+#if FREEDFLY
 static int get_sysctl_pci_bus_info(int maj, int min, drmPciBusInfoPtr info)
 {
     char dname[SPECNAMELEN];
@@ -3255,7 +3265,7 @@ static int drmParsePciBusInfo(int maj, i
     info->func = pinfo.func;
 
     return 0;
-#elif __FreeBSD__
+#elif FREEDFLY
     return get_sysctl_pci_bus_info(maj, min, info);
 #else
 #warning "Missing implementation of drmParsePciBusInfo"
@@ -3424,7 +3434,7 @@ static int drmParsePciDeviceInfo(int maj
     device->subdevice_id = pinfo.subdevice_id;
 
     return 0;
-#elif __FreeBSD__
+#elif FREEDFLY
     drmPciBusInfo info;
     struct pci_conf_io pc;
     struct pci_match_conf patterns[1];
@@ -4302,7 +4312,7 @@ drm_public char *drmGetDeviceNameFromFd2
     free(value);
 
     return strdup(path);
-#elif __FreeBSD__
+#elif FREEDFLY
     return drmGetDeviceNameFromFd(fd);
 #else
     struct stat      sbuf;
