--- solenv/gbuild/UnpackedTarball.mk.orig	2020-07-15 18:21:20 UTC
+++ solenv/gbuild/UnpackedTarball.mk
@@ -23,6 +23,7 @@ $(GNUTAR) \
 	-x \
 	$(3) \
 	-C $(UNPACKED_DIR) \
+	--no-same-owner --no-same-permissions \
 	$(STRIP_COMPONENTS)=$(UNPACKED_STRIP_COMPONENTS) \
 	-f $(UNPACKED_TARBALL)
 endef
