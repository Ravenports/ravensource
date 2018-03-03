--- library.mak.orig	2018-02-12 21:25:59 UTC
+++ library.mak
@@ -71,7 +71,7 @@ install-lib$(NAME)-headers: $(addprefix
 	$(Q)mkdir -p "$(INCINSTDIR)"
 	$$(INSTALL) -m 644 $$^ "$(INCINSTDIR)"
 
-install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME).pc
+install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME)-libav.pc
 	$(Q)mkdir -p "$(LIBDIR)/pkgconfig"
 	$$(INSTALL) -m 644 $$^ "$(LIBDIR)/pkgconfig"
 
