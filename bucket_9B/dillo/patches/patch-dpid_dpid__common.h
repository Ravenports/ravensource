--- dpid/dpid_common.h.orig	2015-06-30 14:06:08 UTC
+++ dpid/dpid_common.h
@@ -38,10 +38,10 @@
 
 
 /*! Error codes for dpid */
-enum {
+enum dpi_errno {
    no_errors,
    dpid_srs_addrinuse /* dpid service request socket address already in use */
-} dpi_errno;
+};
 
 /*! Intended for identifying dillo plugins
  * and related files
