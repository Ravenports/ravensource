--- solenv/gbuild/UnpackedTarball.mk.orig	2024-09-23 13:53:35 UTC
+++ solenv/gbuild/UnpackedTarball.mk
@@ -23,6 +23,7 @@ $(GNUTAR) \
 	-x \
 	$(3) \
 	-C $(UNPACKED_DIR) \
+	--no-same-owner --no-same-permissions \
 	$(STRIP_COMPONENTS)=$(UNPACKED_STRIP_COMPONENTS) \
 	-f $(call gb_Helper_cyg_path,$(UNPACKED_TARBALL))
 endef
