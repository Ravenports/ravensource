--- solenv/gbuild/UnpackedTarball.mk.orig	2023-03-24 16:53:38 UTC
+++ solenv/gbuild/UnpackedTarball.mk
@@ -23,6 +23,7 @@ $(GNUTAR) \
 	-x \
 	$(3) \
 	-C $(UNPACKED_DIR) \
+	--no-same-owner --no-same-permissions \
 	$(STRIP_COMPONENTS)=$(UNPACKED_STRIP_COMPONENTS) \
 	-f $(UNPACKED_TARBALL)
 endef
