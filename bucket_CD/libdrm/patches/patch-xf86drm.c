--- xf86drm.c.orig	2020-04-03 12:28:15 UTC
+++ xf86drm.c
@@ -31,6 +31,12 @@
  * DEALINGS IN THE SOFTWARE.
  */
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#define FREEDFLY 1
+#else
+#define FREEDFLY 0
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
@@ -57,6 +63,12 @@
 #ifdef MAJOR_IN_SYSMACROS
 #include <sys/sysmacros.h>
 #endif
+#if FREEDFLY
+#include <sys/pciio.h>
+#endif
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
 #include <math.h>
 
 #define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
@@ -71,8 +83,12 @@
 
 #include "util_math.h"
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#define DRM_MAJOR 145
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
+#if FREEDFLY
+#define DRM_MAJOR 0	/* Major ID unused on systems with devfs */
 #endif
 
 #ifdef __NetBSD__
@@ -212,6 +228,63 @@ drm_public drmHashEntry *drmGetEntry(int
     return entry;
 }
 
+#if FREEDFLY
+static int drmGetMinorBase(int type)
+{
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+        case DRM_NODE_CONTROL:
+        case DRM_NODE_RENDER:
+            return type << 6;
+        default:
+            return -1;
+    };
+}
+
+static int drmGetMinorType(int minor)
+{
+    int type;
+
+    if (minor < 0)
+        return -1;
+
+    type = minor >> 6;
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+        case DRM_NODE_CONTROL:
+        case DRM_NODE_RENDER:
+            return type;
+        default:
+            return -1;
+    }
+}
+
+static int drmGetNodeNumber(const char *name)
+{
+    size_t name_len = strnlen(name, DRM_NODE_NAME_MAX);
+    while (name_len && isdigit(name[name_len - 1]))
+        --name_len;
+    return strtol(name + name_len, NULL, 10);
+}
+#endif /* FREEDFLY */
+
+static int drmGetNodeType(const char *name)
+{
+    if (strncmp(name, DRM_PRIMARY_MINOR_NAME,
+                sizeof(DRM_PRIMARY_MINOR_NAME) - 1) == 0)
+        return DRM_NODE_PRIMARY;
+
+    if (strncmp(name, DRM_CONTROL_MINOR_NAME,
+                sizeof(DRM_CONTROL_MINOR_NAME ) - 1) == 0)
+        return DRM_NODE_CONTROL;
+
+    if (strncmp(name, DRM_RENDER_MINOR_NAME,
+                sizeof(DRM_RENDER_MINOR_NAME) - 1) == 0)
+        return DRM_NODE_RENDER;
+
+    return -EINVAL;
+}
+
 /**
  * Compare two busid strings
  *
@@ -343,7 +416,11 @@ static int drmOpenDevice(dev_t dev, int
     if (!dev_name)
         return -EINVAL;
 
+#if FREEDFLY
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     drmMsg("drmOpenDevice: node name is %s\n", buf);
 
     if (drm_server_info && drm_server_info->get_perms) {
@@ -456,7 +533,11 @@ static int drmOpenMinor(int minor, int c
     if (!dev_name)
         return -EINVAL;
 
+#if FREEDFLY
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     if ((fd = open(buf, O_RDWR | O_CLOEXEC, 0)) >= 0)
         return fd;
     return -errno;
@@ -497,6 +578,7 @@ drm_public int drmAvailable(void)
     return retval;
 }
 
+#if !FREEDFLY
 static int drmGetMinorBase(int type)
 {
     switch (type) {
@@ -527,7 +609,9 @@ static int drmGetMinorType(int minor)
         return -1;
     }
 }
+#endif /* !FREEDFLY */
 
+#ifdef __linux__
 static const char *drmGetMinorName(int type)
 {
     switch (type) {
@@ -541,6 +625,7 @@ static const char *drmGetMinorName(int t
         return NULL;
     }
 }
+#endif
 
 /**
  * Open the device by bus ID.
@@ -2552,7 +2637,7 @@ drm_public int drmCommandNone(int fd, un
 {
     unsigned long request;
 
-    request = DRM_IO( DRM_COMMAND_BASE + drmCommandIndex);
+    request = DRM_IO( (DRM_COMMAND_BASE + drmCommandIndex) );
 
     if (drmIoctl(fd, request, NULL)) {
         return -errno;
@@ -2744,7 +2829,6 @@ drm_public int drmIsMaster(int fd)
 
 drm_public char *drmGetDeviceNameFromFd(int fd)
 {
-    char name[128];
     struct stat sbuf;
     dev_t d;
     int i;
@@ -2758,14 +2842,12 @@ drm_public char *drmGetDeviceNameFromFd(
     d = sbuf.st_rdev;
 
     for (i = 0; i < DRM_MAX_MINOR; i++) {
+        char name[DRM_NODE_NAME_MAX];
         snprintf(name, sizeof name, DRM_DEV_NAME, DRM_DIR_NAME, i);
         if (stat(name, &sbuf) == 0 && sbuf.st_rdev == d)
-            break;
+            return strdup(name);
     }
-    if (i == DRM_MAX_MINOR)
-        return NULL;
-
-    return strdup(name);
+    return NULL;
 }
 
 static bool drmNodeIsDRM(int maj, int min)
@@ -2784,6 +2866,20 @@ static bool drmNodeIsDRM(int maj, int mi
 
 drm_public int drmGetNodeTypeFromFd(int fd)
 {
+#if FREEDFLY
+    char *name = drmGetDeviceNameFromFd2(fd);
+    int type;
+    if (!name) {
+        errno = ENODEV;
+        return -1;
+    }
+
+    type = drmGetNodeType(name);
+    free(name);
+    if (type < 0)
+        errno = ENODEV;
+    return type;
+#else
     struct stat sbuf;
     int maj, min, type;
 
@@ -2802,6 +2898,7 @@ drm_public int drmGetNodeTypeFromFd(int
     if (type == -1)
         errno = ENODEV;
     return type;
+#endif /* FREEDFLY */
 }
 
 drm_public int drmPrimeHandleToFD(int fd, uint32_t handle, uint32_t flags,
@@ -2880,6 +2977,23 @@ static char *drmGetMinorNameForFD(int fd
 
     closedir(sysdir);
     return NULL;
+#elif FREEDFLY
+    int oldnum, oldtype, newnum;
+    const char *dev_name = drmGetDeviceName(type);
+    char *name = drmGetDeviceNameFromFd2(fd);
+    if (!dev_name || !name)
+        return NULL;
+
+    oldnum = drmGetNodeNumber(name);
+    oldtype = drmGetMinorType(oldnum);
+    if (oldtype < 0) {
+        free(name);
+        return NULL;
+    }
+
+    newnum = oldnum - drmGetMinorBase(oldtype) + drmGetMinorBase(type);
+    snprintf(name, DRM_NODE_NAME_MAX, dev_name, DRM_DIR_NAME, newnum);
+    return name;
 #else
     struct stat sbuf;
     char buf[PATH_MAX + 1];
@@ -2900,7 +3014,7 @@ static char *drmGetMinorNameForFD(int fd
         return NULL;
 
     n = snprintf(buf, sizeof(buf), dev_name, DRM_DIR_NAME, min);
-    if (n == -1 || n >= sizeof(buf))
+    if (n == -1 || n >= (int)sizeof(buf))
         return NULL;
 
     return strdup(buf);
@@ -3019,7 +3133,7 @@ static int drmParseSubsystemType(int maj
         subsystem_type = get_subsystem_type(path);
     }
     return subsystem_type;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__OpenBSD__) || FREEDFLY
     return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
@@ -3027,6 +3141,7 @@ static int drmParseSubsystemType(int maj
 #endif
 }
 
+#ifdef __linux__
 static void
 get_pci_path(int maj, int min, char *pci_path)
 {
@@ -3042,8 +3157,10 @@ get_pci_path(int maj, int min, char *pci
     if (term && strncmp(term, "/virtio", 7) == 0)
         *term = 0;
 }
+#endif
 
-static int drmParsePciBusInfo(int maj, int min, drmPciBusInfoPtr info)
+static int drmParsePciBusInfo(const char *node, int node_type,
+                              int maj, int min, drmPciBusInfoPtr info)
 {
 #ifdef __linux__
     unsigned int domain, bus, dev, func;
@@ -3068,7 +3185,62 @@ static int drmParsePciBusInfo(int maj, i
     info->func = func;
 
     return 0;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif FREEDFLY
+    /*
+     * Only the primary nodes can be mapped to hw.dri.%i via major/minor
+     * Determine the primary node by offset and use its major/minor pair
+     */
+    if (node_type != DRM_NODE_PRIMARY) {
+        char name[DRM_NODE_NAME_MAX];
+        stat_t sbuf;
+        snprintf(name, sizeof(name), DRM_DEV_NAME, DRM_DIR_NAME,
+                 drmGetNodeNumber(node) - drmGetMinorBase(node_type));
+
+        if (stat(name, &sbuf))
+            return -errno;
+
+        maj = major(sbuf.st_rdev);
+        min = minor(sbuf.st_rdev);
+    }
+    /*
+     * Major/minor appear after the driver name in the hw.dri.%i.name node
+     * Find the node with matching major/minor pair and parse the bus ID,
+     * which may be after the name or may be alone in hw.dri.%i.busid
+     */
+    #define bus_fmt "pci:%04x:%02x:%02x.%u"
+    #define name_fmt "%*s %x " bus_fmt
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char name[16], value[256];
+        unsigned int rdev = 0, domain = 0, bus = 0, slot = 0, func = 0;
+        int vals;
+        size_t length = sizeof(value);
+        snprintf(name, sizeof(name), "hw.dri.%i.name", i);
+        if (sysctlbyname(name, value, &length, NULL, 0))
+            continue;
+
+        value[length] = '\0';
+        vals = sscanf(value, name_fmt, &rdev, &domain, &bus, &slot, &func);
+
+	if (vals >= 1 && rdev == makedev(maj,min)) {
+            if (vals < 5) {
+                /* busid not in the name, try busid */
+                length = sizeof(value);
+                snprintf(name, sizeof(name), "hw.dri.%i.busid", i);
+                if (sysctlbyname(name, value, &length, NULL, 0))
+                    break;
+                value[length] = '\0';
+                if (sscanf(value, bus_fmt, &domain, &bus, &slot, &func) != 4)
+                    break;
+            }
+            info->domain = domain;
+            info->bus = bus;
+            info->dev = slot;
+            info->func = func;
+            return 0;
+        }
+    }
+    return -ENODEV;
+#elif defined(__OpenBSD__)
     struct drm_pciinfo pinfo;
     int fd, type;
 
@@ -3126,32 +3298,6 @@ drm_public int drmDevicesEqual(drmDevice
     return 0;
 }
 
-static int drmGetNodeType(const char *name)
-{
-    if (strncmp(name, DRM_CONTROL_MINOR_NAME,
-        sizeof(DRM_CONTROL_MINOR_NAME ) - 1) == 0)
-        return DRM_NODE_CONTROL;
-
-    if (strncmp(name, DRM_RENDER_MINOR_NAME,
-        sizeof(DRM_RENDER_MINOR_NAME) - 1) == 0)
-        return DRM_NODE_RENDER;
-
-    if (strncmp(name, DRM_PRIMARY_MINOR_NAME,
-        sizeof(DRM_PRIMARY_MINOR_NAME) - 1) == 0)
-        return DRM_NODE_PRIMARY;
-
-    return -EINVAL;
-}
-
-static int drmGetMaxNodeName(void)
-{
-    return sizeof(DRM_DIR_NAME) +
-           MAX3(sizeof(DRM_PRIMARY_MINOR_NAME),
-                sizeof(DRM_CONTROL_MINOR_NAME),
-                sizeof(DRM_RENDER_MINOR_NAME)) +
-           3 /* length of the node number */;
-}
-
 #ifdef __linux__
 static int parse_separate_sysfs_files(int maj, int min,
                                       drmPciDeviceInfoPtr device,
@@ -3223,6 +3369,7 @@ static int parse_config_sysfs_file(int m
 #endif
 
 static int drmParsePciDeviceInfo(int maj, int min,
+                                 drmPciBusInfoPtr info,
                                  drmPciDeviceInfoPtr device,
                                  uint32_t flags)
 {
@@ -3234,7 +3381,44 @@ static int drmParsePciDeviceInfo(int maj
         return parse_config_sysfs_file(maj, min, device);
 
     return 0;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif FREEDFLY
+    struct pci_conf_io pc;
+    struct pci_match_conf patterns[1];
+    struct pci_conf results[1];
+
+    int fd = open("/dev/pci", O_RDONLY, 0);
+    if (fd < 0)
+        return -errno;
+
+    bzero(&patterns, sizeof(patterns));
+    patterns[0].pc_sel.pc_domain = info->domain;
+    patterns[0].pc_sel.pc_bus = info->bus;
+    patterns[0].pc_sel.pc_dev = info->dev;
+    patterns[0].pc_sel.pc_func = info->func;
+    patterns[0].flags = PCI_GETCONF_MATCH_DOMAIN | PCI_GETCONF_MATCH_BUS
+                      | PCI_GETCONF_MATCH_DEV | PCI_GETCONF_MATCH_FUNC;
+    bzero(&pc, sizeof(struct pci_conf_io));
+    pc.num_patterns = 1;
+    pc.pat_buf_len = sizeof(patterns);
+    pc.patterns = patterns;
+    pc.match_buf_len = sizeof(results);
+    pc.matches = results;
+
+    if (ioctl(fd, PCIOCGETCONF, &pc) || pc.status == PCI_GETCONF_ERROR) {
+        int error = errno;
+        close(fd);
+        return -error;
+    }
+    close(fd);
+
+    device->vendor_id = results[0].pc_vendor;
+    device->device_id = results[0].pc_device;
+    device->subvendor_id = results[0].pc_subvendor;
+    device->subdevice_id = results[0].pc_subdevice;
+    device->revision_id = results[0].pc_revid;
+
+    return 0;
+#elif defined(__OpenBSD__)
     struct drm_pciinfo pinfo;
     int fd, type;
 
@@ -3339,7 +3523,7 @@ static drmDevicePtr drmDeviceAlloc(unsig
     unsigned int i;
     char *ptr;
 
-    max_node_length = ALIGN(drmGetMaxNodeName(), sizeof(void *));
+    max_node_length = ALIGN(DRM_NODE_NAME_MAX, sizeof(void *));
     extra = DRM_NODE_MAX * (sizeof(void *) + max_node_length);
 
     size = sizeof(*device) + extra + bus_size + device_size;
@@ -3385,7 +3569,7 @@ static int drmProcessPciDevice(drmDevice
 
     dev->businfo.pci = (drmPciBusInfoPtr)addr;
 
-    ret = drmParsePciBusInfo(maj, min, dev->businfo.pci);
+    ret = drmParsePciBusInfo(node, node_type, maj, min, dev->businfo.pci);
     if (ret)
         goto free_device;
 
@@ -3394,7 +3578,7 @@ static int drmProcessPciDevice(drmDevice
         addr += sizeof(drmPciBusInfo);
         dev->deviceinfo.pci = (drmPciDeviceInfoPtr)addr;
 
-        ret = drmParsePciDeviceInfo(maj, min, dev->deviceinfo.pci, flags);
+        ret = drmParsePciDeviceInfo(maj, min, dev->businfo.pci, dev->deviceinfo.pci, flags);
         if (ret)
             goto free_device;
     }
@@ -3696,7 +3880,7 @@ process_device(drmDevicePtr *device, con
                bool fetch_deviceinfo, uint32_t flags)
 {
     struct stat sbuf;
-    char node[PATH_MAX + 1];
+    char node[DRM_NODE_NAME_MAX];
     int node_type, subsystem_type;
     unsigned int maj, min;
 
@@ -3704,14 +3888,14 @@ process_device(drmDevicePtr *device, con
     if (node_type < 0)
         return -1;
 
-    snprintf(node, PATH_MAX, "%s/%s", DRM_DIR_NAME, d_name);
+    snprintf(node, sizeof(node), "%s/%s", DRM_DIR_NAME, d_name);
     if (stat(node, &sbuf))
         return -1;
 
     maj = major(sbuf.st_rdev);
     min = minor(sbuf.st_rdev);
 
-    if (!drmNodeIsDRM(maj, min) || !S_ISCHR(sbuf.st_mode))
+    if ((DRM_MAJOR && maj != DRM_MAJOR) || !S_ISCHR(sbuf.st_mode))
         return -1;
 
     subsystem_type = drmParseSubsystemType(maj, min);
@@ -3751,7 +3935,7 @@ static void drmFoldDuplicatedDevices(drm
                 local_devices[i]->available_nodes |= local_devices[j]->available_nodes;
                 node_type = log2(local_devices[j]->available_nodes);
                 memcpy(local_devices[i]->nodes[node_type],
-                       local_devices[j]->nodes[node_type], drmGetMaxNodeName());
+                       local_devices[j]->nodes[node_type], DRM_NODE_NAME_MAX);
                 drmFreeDevice(&local_devices[j]);
             }
         }
@@ -3810,7 +3994,7 @@ drm_public int drmGetDevice2(int fd, uin
      */
     drmDevicePtr     d;
     struct stat      sbuf;
-    char             node[PATH_MAX + 1];
+    char             node[DRM_NODE_NAME_MAX];
     const char      *dev_name;
     int              node_type, subsystem_type;
     int              maj, min, n, ret;
@@ -3824,7 +4008,7 @@ drm_public int drmGetDevice2(int fd, uin
     maj = major(sbuf.st_rdev);
     min = minor(sbuf.st_rdev);
 
-    if (!drmNodeIsDRM(maj, min) || !S_ISCHR(sbuf.st_mode))
+    if (DRM_MAJOR && !drmNodeIsDRM(maj, min) || !S_ISCHR(sbuf.st_mode))
         return -EINVAL;
 
     node_type = drmGetMinorType(min);
@@ -3835,8 +4019,8 @@ drm_public int drmGetDevice2(int fd, uin
     if (!dev_name)
         return -EINVAL;
 
-    n = snprintf(node, PATH_MAX, dev_name, DRM_DIR_NAME, min);
-    if (n == -1 || n >= PATH_MAX)
+    n = snprintf(node, sizeof(node), dev_name, DRM_DIR_NAME, min);
+    if (n == -1 || n >= (int)sizeof(node))
       return -errno;
     if (stat(node, &sbuf))
         return -EINVAL;
@@ -4050,9 +4234,27 @@ drm_public char *drmGetDeviceNameFromFd2
     free(value);
 
     return strdup(path);
+#elif FREEDFLY
+    stat_t sbuf;
+    dev_t rdev;
+    if (fstat(fd, &sbuf))
+        return NULL;
+
+    rdev = sbuf.st_rdev;
+    /* minor numbers don't depend on node name suffix, search for a match */
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char node[DRM_NODE_NAME_MAX];
+        for (int j = 0; j < DRM_NODE_MAX; ++j) {
+            snprintf(node, sizeof(node), drmGetDeviceName(j),
+                     DRM_DIR_NAME, drmGetMinorBase(j) + i);
+            if (stat(node, &sbuf) == 0 && sbuf.st_rdev == rdev)
+                return strdup(node);
+        }
+    }
+    return NULL;
 #else
     struct stat      sbuf;
-    char             node[PATH_MAX + 1];
+    char             node[DRM_NODE_NAME_MAX];
     const char      *dev_name;
     int              node_type;
     int              maj, min, n;
@@ -4074,8 +4276,8 @@ drm_public char *drmGetDeviceNameFromFd2
     if (!dev_name)
         return NULL;
 
-    n = snprintf(node, PATH_MAX, dev_name, DRM_DIR_NAME, min);
-    if (n == -1 || n >= PATH_MAX)
+    n = snprintf(node, sizeof(node), dev_name, DRM_DIR_NAME, min);
+    if (n == -1 || n >= (int)sizeof(node))
       return NULL;
 
     return strdup(node);
