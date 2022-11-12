--- xf86drm.c.orig	2022-11-03 08:33:36 UTC
+++ xf86drm.c
@@ -63,7 +63,17 @@
 #include <math.h>
 #include <inttypes.h>
 
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
@@ -313,8 +323,10 @@ drmGetFormatModifierNameFromArm(uint64_t
     char *modifier_name = NULL;
     bool result = false;
 
+#ifndef __sun
     fp = open_memstream(&modifier_name, &size);
     if (!fp)
+#endif
         return NULL;
 
     switch (type) {
@@ -459,8 +471,10 @@ drmGetFormatModifierNameFromAmd(uint64_t
     tile_version = AMD_FMT_MOD_GET(TILE_VERSION, modifier);
     dcc = AMD_FMT_MOD_GET(DCC, modifier);
 
+#ifndef __sun
     fp = open_memstream(&mod_amd, &size);
     if (!fp)
+#endif
         return NULL;
 
     /* add tile  */
@@ -963,7 +977,7 @@ static int drmGetMinorBase(int type)
 
 static int drmGetMinorType(int major, int minor)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     char name[SPECNAMELEN];
     int id;
 
@@ -3219,7 +3233,7 @@ drm_public int drmIsMaster(int fd)
 
 drm_public char *drmGetDeviceNameFromFd(int fd)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     struct stat sbuf;
     int maj, min;
     int nodetype;
@@ -3266,7 +3280,7 @@ static bool drmNodeIsDRM(int maj, int mi
     snprintf(path, sizeof(path), "/sys/dev/char/%d:%d/device/drm",
              maj, min);
     return stat(path, &sbuf) == 0;
-#elif defined(__FreeBSD__)
+#elif FREEDFLY
     char name[SPECNAMELEN];
 
     if (!devname_r(makedev(maj, min), S_IFCHR, name, sizeof(name)))
@@ -3389,7 +3403,7 @@ static char *drmGetMinorNameForFD(int fd
 
     closedir(sysdir);
     return NULL;
-#elif defined(__FreeBSD__)
+#elif FREEDFLY
     struct stat sbuf;
     char dname[SPECNAMELEN];
     const char *mname;
@@ -3600,7 +3614,7 @@ get_pci_path(int maj, int min, char *pci
 }
 #endif
 
-#ifdef __FreeBSD__
+#if FREEDFLY
 static int get_sysctl_pci_bus_info(int maj, int min, drmPciBusInfoPtr info)
 {
     char dname[SPECNAMELEN];
