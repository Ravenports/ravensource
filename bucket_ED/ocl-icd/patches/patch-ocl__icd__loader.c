--- ocl_icd_loader.c.orig	2017-01-19 13:55:12 UTC
+++ ocl_icd_loader.c
@@ -53,11 +53,23 @@ int debug_ocl_icd_mask=0;
 
 typedef __typeof__(clGetPlatformInfo) *clGetPlatformInfo_fn;
 
-inline void dump_vendor_icd(const char* info, const struct vendor_icd *v) {
+static inline void dump_vendor_icd(const char* info, const struct vendor_icd *v) {
   debug(D_DUMP, "%s %p={ num=%i, handle=%p, f=%p}\n", info,
 	v, v->num_platforms, v->dl_handle, v->ext_fn_ptr);
 }
 
+#ifdef __sun__
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+#endif
+
 struct vendor_icd *_icds=NULL;
 struct platform_icd *_picds=NULL;
 static cl_uint _num_icds = 0;
