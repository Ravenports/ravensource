--- make/libtool.mk.orig	2021-11-16 20:44:09 UTC
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
-# LIBTOOL needs bash
-SHELL=/bin/bash
+# LIBTOOL needs sh
+SHELL=/bin/sh
 
 OBJ=o
 LOBJ=lo
@@ -108,7 +108,7 @@ endef
 install-libs: build_libqpdf
 	./mkinstalldirs -m 0755 $(DESTDIR)$(libdir)/pkgconfig
 	./mkinstalldirs -m 0755 $(DESTDIR)$(includedir)/qpdf
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		libqpdf/$(OUTPUT_DIR)/libqpdf.la \
 		$(DESTDIR)$(libdir)/libqpdf.la
 	$(LIBTOOL) --finish $(DESTDIR)$(libdir)
@@ -124,13 +124,13 @@ install: all install-libs
 	./mkinstalldirs -m 0755 $(DESTDIR)$(bindir)
 	./mkinstalldirs -m 0755 $(DESTDIR)$(docdir)
 	./mkinstalldirs -m 0755 $(DESTDIR)$(mandir)/man1
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		qpdf/$(OUTPUT_DIR)/qpdf \
 		$(DESTDIR)$(bindir)/qpdf
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		zlib-flate/$(OUTPUT_DIR)/zlib-flate \
 		$(DESTDIR)$(bindir)/zlib-flate
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		qpdf/$(OUTPUT_DIR)/fix-qdf \
 		$(DESTDIR)$(bindir)/fix-qdf
 	./install-sh -m 0644 doc/stylesheet.css $(DESTDIR)$(docdir)
