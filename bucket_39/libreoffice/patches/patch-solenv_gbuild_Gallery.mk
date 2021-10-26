Seems to be needed by NetBSD shell to get past the fact no files are generated.

--- solenv/gbuild/Gallery.mk.orig	2021-10-06 00:34:15 UTC
+++ solenv/gbuild/Gallery.mk
@@ -26,7 +26,7 @@ $(call gb_Helper_abbreviate_dirs,\
 			--path $(call gb_Gallery_get_workdir,$(2)) \
 			--filenames $(call gb_Helper_make_url,$$RESPONSEFILE),\
 		$@.log \
-	) && \
+	) ||: true && \
 	rm $$RESPONSEFILE && \
 	touch $@ \
 )
