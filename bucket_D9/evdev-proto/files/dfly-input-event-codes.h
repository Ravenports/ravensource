--- input-event-codes.h.orig	2021-03-28 18:59:39 UTC
+++ input-event-codes.h
@@ -758,6 +758,15 @@
 
 #define	ABS_MISC		0x28
 
+/*
+ * 0x2e is reserved and should not be used in input drivers.
+ * It was used by HID as ABS_MISC+6 and userspace needs to detect if
+ * the next ABS_* event is correct or is just ABS_MISC + n.
+ * We define here ABS_RESERVED so userspace can rely on it and detect
+ * the situation described above.
+ */
+#define ABS_RESERVED		0x2e
+
 #define	ABS_MT_SLOT		0x2f	/* MT slot being modified */
 #define	ABS_MT_TOUCH_MAJOR	0x30	/* Major axis of touching ellipse */
 #define	ABS_MT_TOUCH_MINOR	0x31	/* Minor axis (omit if circular) */
