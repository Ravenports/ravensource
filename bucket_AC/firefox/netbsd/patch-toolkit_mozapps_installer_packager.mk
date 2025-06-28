$NetBSD: patch-toolkit_mozapps_installer_packager.mk,v 1.5 2025/04/30 03:47:13 ryoon Exp $

* Symbolic link to lib/firefox/firefox causes 'Couldn't load XPCOM.' error.

--- toolkit/mozapps/installer/packager.mk.orig	2025-06-07 15:37:16 UTC
+++ toolkit/mozapps/installer/packager.mk
@@ -169,7 +169,6 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 upload:
 	$(PYTHON3) -u $(MOZILLA_DIR)/build/upload.py --base-path $(DIST) $(UPLOAD_FILES)
