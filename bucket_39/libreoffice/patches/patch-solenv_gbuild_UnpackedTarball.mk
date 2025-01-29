--- solenv/gbuild/UnpackedTarball.mk.orig	2025-01-23 21:25:49 UTC
+++ solenv/gbuild/UnpackedTarball.mk
@@ -23,6 +23,7 @@ $(GNUTAR) \
 	-x \
 	$(3) \
 	-C $(UNPACKED_DIR) \
+	--no-same-owner --no-same-permissions \
 	$(STRIP_COMPONENTS)=$(UNPACKED_STRIP_COMPONENTS) \
 	-f $(call gb_Helper_cyg_path,$(UNPACKED_TARBALL))
 endef
