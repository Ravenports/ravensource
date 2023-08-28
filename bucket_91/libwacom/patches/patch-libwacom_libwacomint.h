--- libwacom/libwacomint.h.orig	2023-01-23 05:42:27 UTC
+++ libwacom/libwacomint.h
@@ -132,6 +132,9 @@ WacomStylus* libwacom_stylus_unref(Wacom
 WacomMatch* libwacom_match_ref(WacomMatch *match);
 WacomMatch* libwacom_match_unref(WacomMatch *match);
 
+#define libwacom_error_set libwacom_internal_error_set
+#define libwacom_match_new libwacom_internal_match_new
+
 void libwacom_error_set(WacomError *error, enum WacomErrorCode code, const char *msg, ...);
 void libwacom_add_match(WacomDevice *device, WacomMatch *newmatch);
 void libwacom_set_default_match(WacomDevice *device, WacomMatch *newmatch);
