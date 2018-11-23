i915 does not use hw.dri.0.busid
so simplify to basics.

--- src/intel_device.c.orig	2018-09-06 12:00:04 UTC
+++ src/intel_device.c
@@ -28,6 +28,9 @@
 #include "config.h"
 #endif
 
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
@@ -424,6 +427,10 @@ static int __intel_open_device__legacy(c
 		 "pci:%04x:%02x:%02x.%d",
 		 pci->domain, pci->bus, pci->dev, pci->func);
 
+#if defined(__DragonFly__)
+	/* assume modesetting for i915, allow multiple loads and no fbcon */
+	load_i915_kernel_module();
+#else
 	ret = drmCheckModesettingSupported(id);
 	if (ret) {
 		if (load_i915_kernel_module() == 0)
@@ -433,6 +440,7 @@ static int __intel_open_device__legacy(c
 		/* Be nice to the user and load fbcon too */
 		(void)xf86LoadKernelModule("fbcon");
 	}
+#endif
 
 	return fd_set_nonblock(drmOpen(NULL, id));
 }
