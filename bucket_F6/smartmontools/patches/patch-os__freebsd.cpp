--- os_freebsd.cpp.orig	2018-12-05 18:30:46 UTC
+++ os_freebsd.cpp
@@ -9,6 +9,7 @@
  */
 
 #include <sys/param.h>
+#include <sys/endian.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <dirent.h>
@@ -16,11 +17,13 @@
 #include <err.h>
 #include <errno.h>
 #include <camlib.h>
-#include <cam/scsi/scsi_message.h>
-#include <cam/scsi/scsi_pass.h>
 #if defined(__DragonFly__)
+#include <bus/cam/scsi/scsi_message.h>
+#include <bus/cam/scsi/scsi_pass.h>
 #include <sys/nata.h>
 #else
+#include <cam/scsi/scsi_message.h>
+#include <cam/scsi/scsi_pass.h>
 #include <sys/ata.h>
 #endif
 #include <sys/stat.h>
@@ -53,13 +56,15 @@
 #define FREEBSDVER __FreeBSD_kernel_version
 #endif
 
-#if (FREEBSDVER >= 800000)
+#ifdef __DragonFly__
+#define  DFU4B 1
+#include <libusb20_desc.h>
+#include <libusb20.h>
+#include <bus/u4b/usb.h>
+#include <bus/u4b/usbhid.h>
+#elif (FREEBSDVER >= 800000)
 #include <libusb20_desc.h>
 #include <libusb20.h>
-#elif defined(__DragonFly__)
-#include <bus/usb/usb.h>
-#include <bus/usb/usbhid.h>
-#else
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 #endif
@@ -522,29 +527,29 @@ bool freebsd_nvme_device::nvme_pass_thro
   pt.cmd.opc = in.opcode;
 #endif
   pt.cmd.opc = in.opcode;
-  pt.cmd.nsid = in.nsid;
+  pt.cmd.nsid = htole32(in.nsid);
   pt.buf = in.buffer;
   pt.len = in.size;
-  pt.cmd.cdw10 = in.cdw10;
-  pt.cmd.cdw11 = in.cdw11;
-  pt.cmd.cdw12 = in.cdw12;
-  pt.cmd.cdw13 = in.cdw13;
-  pt.cmd.cdw14 = in.cdw14;
-  pt.cmd.cdw15 = in.cdw15;
+  pt.cmd.cdw10 = htole32(in.cdw10);
+  pt.cmd.cdw11 = htole32(in.cdw11);
+  pt.cmd.cdw12 = htole32(in.cdw12);
+  pt.cmd.cdw13 = htole32(in.cdw13);
+  pt.cmd.cdw14 = htole32(in.cdw14);
+  pt.cmd.cdw15 = htole32(in.cdw15);
   pt.is_read = 1; // should we use in.direction()?
   
   int status = ioctl(get_fd(), NVME_PASSTHROUGH_CMD, &pt);
 
   if (status < 0)
     return set_err(errno, "NVME_PASSTHROUGH_CMD: %s", strerror(errno));
-
+#if __FreeBSD_version >= 1200058
+  nvme_completion_swapbytes(&pt.cpl);
+#endif
   cp_p = &pt.cpl;
   out.result=cp_p->cdw0; // Command specific result (DW0)
 
   if (nvme_completion_is_error(cp_p)) {  /* ignore DNR and More bits */
-    uint16_t nvme_status = ((cp_p->status.sct << 8) | cp_p->status.sc) & 0x3ff;
-
-    return set_nvme_err(out, nvme_status);
+    return set_nvme_err(out, nvme_completion_is_error(&pt.cpl));
   }
 
   return true;
@@ -1390,6 +1395,14 @@ smart_device * freebsd_scsi_device::auto
   if (len < 36)
     return this;
 
+#ifdef __DragonFly__
+  if (m_camdev == NULL) {
+      close();
+      set_err(EINVAL, "m_camdev not set");
+      return this;
+  }
+#endif
+
   // Use INQUIRY to detect type
 
   // 3ware ?
@@ -1796,7 +1809,7 @@ bool freebsd_smart_interface::get_nvme_d
   return true;
 }
 
-#if (FREEBSDVER < 800000) // without this build fail on FreeBSD 8
+#if (FREEBSDVER < 800000) && !defined(DFU4B)
 static char done[USB_MAX_DEVICES];
 
 static int usbdevinfo(int f, int a, int rec, int busno, unsigned short & vendor_id,
@@ -1852,7 +1865,7 @@ static int usbdevinfo(int f, int a, int
 static int usbdevlist(int busno,unsigned short & vendor_id,
   unsigned short & product_id, unsigned short & version)
 {
-#if (FREEBSDVER >= 800000) // libusb2 interface
+#if (FREEBSDVER >= 800000) || defined(DFU4B) // libusb2 interface
   struct libusb20_device *pdev = NULL;
   struct libusb20_backend *pbe;
   uint32_t matches = 0;
