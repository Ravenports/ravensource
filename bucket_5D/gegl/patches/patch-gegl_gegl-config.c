--- gegl/gegl-config.c.orig	2020-08-02 20:23:44 UTC
+++ gegl/gegl-config.c
@@ -285,6 +285,21 @@ gegl_config_class_init (GeglConfigClass
                              ) * page_size;
       mach_port_deallocate (mach_task_self (), host);
     }
+#elif defined(__DragonFly__)
+
+    int64_t usermem, free_pages, inact;
+    size_t len = sizeof usermem;
+
+    if(sysctlbyname("hw.usermem", &usermem, &len, NULL, 0)) {
+      mem_total = usermem;
+    };
+
+    if(sysctlbyname("vm.stats.vm.v_free_count", &free_pages, &len, NULL, 0)) {
+	if(sysctlbyname("vm.stats.vm.v_inactive_count", &inact, &len, NULL, 0)) {
+	    mem_available = (free_pages + inact) * sysconf (_SC_PAGESIZE);
+	}
+    };
+
 #elif defined(__FreeBSD__)
     bool ok = true;
 
