--- netbsd/hid.c.orig	2025-05-18 18:25:13 UTC
+++ netbsd/hid.c
@@ -1087,7 +1087,7 @@ int HID_API_EXPORT_CALL hid_get_indexed_
 	struct usb_string_desc usd;
 	usb_string_descriptor_t *str;
 	iconv_t ic;
-	const char *src;
+	char *src;
 	size_t srcleft;
 	char *dst;
 	size_t dstleft;
@@ -1131,7 +1131,7 @@ int HID_API_EXPORT_CALL hid_get_indexed_
 		return -1;
 	}
 
-	src = (const char *) str->bString;
+	src = (char *) str->bString;
 	srcleft = str->bLength - 2;
 	dst = (char *) string;
 	dstleft = sizeof(wchar_t[maxlen]);
