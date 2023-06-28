--- toolkit/xre/glxtest/glxtest.cpp.orig	2023-06-08 22:09:52 UTC
+++ toolkit/xre/glxtest/glxtest.cpp
@@ -195,9 +195,14 @@ extern "C" {
 static void get_pci_status() {
   log("GLX_TEST: get_pci_status start\n");
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+  if (access("/dev/pci", F_OK) != 0) {
+    record_warning("cannot access /dev/pci");
+#else
   if (access("/sys/bus/pci/", F_OK) != 0 &&
       access("/sys/bus/pci_express/", F_OK) != 0) {
     record_warning("cannot access /sys/bus/pci");
+#endif
     return;
   }
 
