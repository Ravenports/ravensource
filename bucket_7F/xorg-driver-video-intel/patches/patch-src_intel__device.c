i915 requires KMS, so FreeBSD uses suffix to distinguish drm1 and drm2 drivers.
drm-kmod kept the same name at the cost of conflict with in-base drm2.

--- src/intel_device.c.orig	2021-01-15 20:59:05 UTC
+++ src/intel_device.c
@@ -204,6 +204,7 @@ static inline struct intel_device *intel
 }
 
 static const char *kernel_module_names[] ={
+	"i915kms",
 	"i915",
 	NULL,
 };
@@ -424,6 +425,10 @@ static int __intel_open_device__legacy(c
 		 "pci:%04x:%02x:%02x.%d",
 		 pci->domain, pci->bus, pci->dev, pci->func);
 
+#if defined(__DragonFly__)
+	/* assume modesetting for i915, allow multiple loads and no fbcon */
+	load_i915_kernel_module();
+#else
 	ret = drmCheckModesettingSupported(id);
 	if (ret) {
 		if (load_i915_kernel_module() == 0)
@@ -433,6 +438,7 @@ static int __intel_open_device__legacy(c
 		/* Be nice to the user and load fbcon too */
 		(void)xf86LoadKernelModule("fbcon");
 	}
+#endif
 
 	return fd_set_nonblock(drmOpen(NULL, id));
 }
