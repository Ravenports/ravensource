--- xf86drm.c.orig	2025-11-02 02:30:31 UTC
+++ xf86drm.c
@@ -63,7 +63,17 @@
 #endif
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
@@ -86,7 +96,10 @@
 #endif
 
 #ifdef __NetBSD__
-#define DRM_MAJOR 34
+#define DRM_MAJOR 180
+#include <sys/param.h>
+#include <dev/pci/pcireg.h>
+#include <pci.h>
 #endif
 
 #ifdef __OpenBSD__
@@ -305,8 +318,10 @@ drmGetFormatModifierNameFromArm(uint64_t
     char *modifier_name = NULL;
     bool result = false;
 
+#ifndef __sun
     fp = open_memstream(&modifier_name, &size);
     if (!fp)
+#endif
         return NULL;
 
     switch (type) {
@@ -410,8 +425,10 @@ drmGetFormatModifierNameFromAmd(uint64_t
     char *mod_amd = NULL;
     size_t size = 0;
 
+#ifndef __sun
     fp = open_memstream(&mod_amd, &size);
     if (!fp)
+#endif
         return NULL;
 
     switch (tile_version) {
@@ -1027,7 +1044,7 @@ static int drmGetMinorBase(int type)
 
 static int drmGetMinorType(int major, int minor)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     char name[SPECNAMELEN];
     int id;
 
@@ -3280,7 +3297,7 @@ drm_public int drmIsMaster(int fd)
 
 drm_public char *drmGetDeviceNameFromFd(int fd)
 {
-#ifdef __FreeBSD__
+#if FREEDFLY
     struct stat sbuf;
     int maj, min;
     int nodetype;
@@ -3327,7 +3344,7 @@ static bool drmNodeIsDRM(int maj, int mi
     snprintf(path, sizeof(path), "/sys/dev/char/%d:%d/device/drm",
              maj, min);
     return stat(path, &sbuf) == 0;
-#elif defined(__FreeBSD__)
+#elif FREEDFLY
     char name[SPECNAMELEN];
 
     if (!devname_r(makedev(maj, min), S_IFCHR, name, sizeof(name)))
@@ -3450,7 +3467,7 @@ static char *drmGetMinorNameForFD(int fd
 
     closedir(sysdir);
     return NULL;
-#elif defined(__FreeBSD__)
+#elif FREEDFLY
     struct stat sbuf;
     char dname[SPECNAMELEN];
     const char *mname;
@@ -3636,6 +3653,65 @@ static int drmParseSubsystemType(int maj
             return DRM_BUS_VIRTIO;
      }
     return subsystem_type;
+#elif defined(__NetBSD__)
+    int type, fd;
+    drmSetVersion sv;
+    char *buf;
+    unsigned domain, bus, dev;
+    int func;
+    int ret;
+
+    /* Get the type of device we're looking for to pick the right pathname.  */
+    type = drmGetMinorType(maj, min);
+    if (type == -1)
+	return -ENODEV;
+
+    /* Open the device.  Don't try to create it if it's not there.  */
+    fd = drmOpenMinor(min, 0, type);
+    if (fd < 0)
+	return -errno;
+
+    /*
+     * Set the interface version to 1.4 or 1.1, which has the effect of
+     * populating the bus id for us.
+     */
+    sv.drm_di_major = 1;
+    sv.drm_di_minor = 4;
+    sv.drm_dd_major = -1;
+    sv.drm_dd_minor = -1;
+    if (drmSetInterfaceVersion(fd, &sv)) {
+	sv.drm_di_major = 1;
+	sv.drm_di_minor = 1;
+	sv.drm_dd_major = -1;
+	sv.drm_dd_minor = -1;
+	if (drmSetInterfaceVersion(fd, &sv)) {
+	    /*
+	     * We're probably not the master.  Hope the master already
+	     * set the version to >=1.1 so that we can get the busid.
+	     */
+	}
+     }
+
+    /* Get the bus id.  */
+    buf = drmGetBusid(fd);
+
+    /* We're done with the device now.  */
+    (void)close(fd);
+
+    /* If there is no bus id, fail.  */
+    if (buf == NULL)
+	return -ENODEV;
+
+    /* Find a string we know about; otherwise -EINVAL.  */
+    ret = -EINVAL;
+    if (strncmp(buf, "pci:", 4) == 0)
+	ret = DRM_BUS_PCI;
+
+    /* We're done with the bus id.  */
+    free(buf);
+
+    /* Success or not, we're done.  */
+    return ret;
 #elif defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
     return DRM_BUS_PCI;
 #else
@@ -3662,7 +3738,7 @@ get_pci_path(int maj, int min, char *pci
 }
 #endif
 
-#ifdef __FreeBSD__
+#if FREEDFLY
 static int get_sysctl_pci_bus_info(int maj, int min, drmPciBusInfoPtr info)
 {
     char dname[SPECNAMELEN];
@@ -3744,6 +3820,73 @@ static int drmParsePciBusInfo(int maj, i
     info->func = func;
 
     return 0;
+#elif defined(__NetBSD__)
+    int type, fd;
+    drmSetVersion sv;
+    char *buf;
+    unsigned domain, bus, dev;
+    int func;
+    int ret;
+
+    /* Get the type of device we're looking for to pick the right pathname.  */
+    type = drmGetMinorType(maj, min);
+    if (type == -1)
+	return -ENODEV;
+
+    /* Open the device.  Don't try to create it if it's not there.  */
+    fd = drmOpenMinor(min, 0, type);
+    if (fd < 0)
+	return -errno;
+
+    /*
+     * Set the interface version to 1.4 or 1.1, which has the effect of
+     * populating the bus id for us.
+     */
+    sv.drm_di_major = 1;
+    sv.drm_di_minor = 4;
+    sv.drm_dd_major = -1;
+    sv.drm_dd_minor = -1;
+    if (drmSetInterfaceVersion(fd, &sv)) {
+	sv.drm_di_major = 1;
+	sv.drm_di_minor = 1;
+	sv.drm_dd_major = -1;
+	sv.drm_dd_minor = -1;
+	if (drmSetInterfaceVersion(fd, &sv)) {
+            /*
+	     * We're probably not the master.  Hope the master already
+	     * set the version to >=1.1 so that we can get the busid.
+	     */
+	}
+    }
+
+    /* Get the bus id.  */
+    buf = drmGetBusid(fd);
+
+    /* We're done with the device now.  */
+    (void)close(fd);
+
+    /* If there is no bus id, fail.  */
+    if (buf == NULL)
+	return -ENODEV;
+
+    /* Parse the bus id.  */
+    ret = sscanf(buf, "pci:%04x:%02x:%02x.%d", &domain, &bus, &dev, &func);
+
+    /* We're done with the bus id.  */
+    free(buf);
+
+    /* If scanf didn't return 4 -- domain, bus, dev, func -- then fail.  */
+    if (ret != 4)
+	return -ENODEV;
+
+    /* Populate the results.  */
+    info->domain = domain;
+    info->bus = bus;
+    info->dev = dev;
+    info->func = func;
+
+    /* Success!  */
+    return 0;
 #elif defined(__OpenBSD__) || defined(__DragonFly__)
     struct drm_pciinfo pinfo;
     int fd, type;
@@ -3915,6 +4058,48 @@ static int drmParsePciDeviceInfo(int maj
         return parse_config_sysfs_file(maj, min, device);
 
     return 0;
+#elif defined(__NetBSD__)
+    drmPciBusInfo businfo;
+    char fname[PATH_MAX];
+    int pcifd;
+    pcireg_t id, class, subsys;
+    int ret;
+
+    /* Find where on the bus the device lives.  */
+    ret = drmParsePciBusInfo(maj, min, &businfo);
+    if (ret)
+	return ret;
+
+    /* Open the pciN device node to get at its config registers.  */
+    if (snprintf(fname, sizeof fname, "/dev/pci%u", businfo.domain)
+	>= sizeof fname)
+	return -ENODEV;
+    if ((pcifd = open(fname, O_RDONLY)) == -1)
+	return -errno;
+
+    ret = -1;
+    /* Read the id and class pci config registers.  */
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_ID_REG, &id) == -1)
+	goto out;
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_CLASS_REG, &class) == -1)
+	goto out;
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_SUBSYS_ID_REG, &subsys) == -1)
+	goto out;
+
+    ret = 0;
+    device->vendor_id = PCI_VENDOR(id);
+    device->device_id = PCI_PRODUCT(id);
+    device->subvendor_id = PCI_SUBSYS_VENDOR(subsys);
+    device->subdevice_id = PCI_SUBSYS_ID(subsys);
+    device->revision_id = PCI_REVISION(class);
+out:
+    if (ret == -1)
+	ret = -errno;
+    close(pcifd);
+    return ret;
 #elif defined(__OpenBSD__) || defined(__DragonFly__)
     struct drm_pciinfo pinfo;
     int fd, type;
