--- cfg/targets/install.mk.orig	2018-02-27 23:46:56 UTC
+++ cfg/targets/install.mk
@@ -27,7 +27,7 @@ install: $(BUILD_DIR)/toxic
 		if [ ! -e "$(DOC_DIR)/$$f" ]; then \
 			continue ;\
 		fi ;\
-		section=$(abspath $(DESTDIR)/$(MANDIR))/man`echo $$f | rev | cut -d "." -f 1` ;\
+		section=$(abspath $(DESTDIR)/$(MANDIR))/man`echo $$f | sed "s/.*\.//"` ;\
 		file=$$section/$$f ;\
 		mkdir -p $$section ;\
 		install -m 0644 $(DOC_DIR)/$$f $$file ;\
