--- src/bsd_kbd.c.orig	2022-07-10 23:28:06 UTC
+++ src/bsd_kbd.c
@@ -237,6 +237,12 @@ KbdOn(InputInfoPtr pInfo, int what)
 #endif
 	}
     }
+/*
+ * Switch keyboards which are not attached to console in RAW mode
+ */
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
+	ioctl(pInfo->fd, KDSKBMODE, K_RAW);
+#endif
     return Success;
 }
 
