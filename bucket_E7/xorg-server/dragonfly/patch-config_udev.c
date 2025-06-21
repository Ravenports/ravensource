--- config/udev.c.orig	2025-06-18 16:25:56 UTC
+++ config/udev.c
@@ -29,6 +29,7 @@
 
 #include <libudev.h>
 #include <ctype.h>
+#include <fcntl.h>
 #include <unistd.h>
 
 #include "input.h"
@@ -67,6 +68,45 @@ config_udev_odev_setup_attribs(struct ud
 
 static char itoa_buf[16];
 
+#if defined(__DragonFly__)
+// Taken from FreeBSD's lib/libc/gen/feature_present.c
+
+#include <sys/cdefs.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+
+int      feature_present(const char *);
+/*
+ * Returns true if the named feature is present in the currently
+ * running kernel.  A feature's presence is indicated by an integer
+ * sysctl node called kern.feature.<feature> that is non-zero.
+ */
+int
+feature_present(const char *feature)
+{
+	char *mib;
+	size_t len;
+	int i;
+
+	if (asprintf(&mib, "kern.features.%s", feature) < 0)
+		return (0);
+	len = sizeof(i);
+	if (sysctlbyname(mib, &i, &len, NULL, 0) < 0) {
+		free(mib);
+		return (0);
+	}
+	free(mib);
+	if (len != sizeof(i))
+		return (0);
+	return (i != 0);
+}
+
+// end of FreeBSD's lib/libc/gen/feature_present.c
+#endif
+
 static const char *itoa(int i)
 {
     snprintf(itoa_buf, sizeof(itoa_buf), "%d", i);
@@ -198,7 +238,21 @@ device_added(struct udev_device *udev_de
         attrs.product = strdup(name);
     input_options = input_option_new(input_options, "name", name);
     input_options = input_option_new(input_options, "path", path);
-    input_options = input_option_new(input_options, "device", path);
+    if(strstr(path, "kbdmux") != NULL) {
+        /*
+         * Don't pass "device" option if the keyboard is already attached
+         * to the console (ie. open() fails). This would activate a special
+         * logic in xf86-input-keyboard. Prevent any other attached to console
+         * keyboards being processed. There can be only one such device.
+         */
+        int fd = open(path, O_RDONLY);
+        if (fd > -1) {
+            close(fd);
+            input_options = input_option_new(input_options, "device", path);
+        }
+    }
+    else
+        input_options = input_option_new(input_options, "device", path);
     input_options = input_option_new(input_options, "major", itoa(major(devnum)));
     input_options = input_option_new(input_options, "minor", itoa(minor(devnum)));
     if (path)
@@ -280,6 +334,18 @@ device_added(struct udev_device *udev_de
         }
     }
 
+    if (attrs.flags & (ATTR_KEY | ATTR_KEYBOARD)) {
+        if (!feature_present("evdev_support"))
+            input_options = input_option_new(input_options, "driver", "kbd");
+    } else if (attrs.flags & ATTR_POINTER) {
+        if (strstr(path, "vbox"))
+            input_options = input_option_new(input_options, "driver", "vboxmouse");
+        else {
+            if (!feature_present("evdev_support"))
+                input_options = input_option_new(input_options, "driver", "mouse");
+        }
+    }
+
     input_options = input_option_new(input_options, "config_info", config_info);
 
     /* Default setting needed for non-seat0 seats */
