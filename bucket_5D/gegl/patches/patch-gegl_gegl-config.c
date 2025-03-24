--- gegl/gegl-config.c.orig	2025-03-16 14:24:24 UTC
+++ gegl/gegl-config.c
@@ -44,7 +44,7 @@
 #include <mach/mach.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
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
 
@@ -319,7 +334,11 @@ gegl_config_class_init (GeglConfigClass
     }
 #else
     mem_total = (uint64_t) sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+# ifdef _SC_AVPHYS_PAGES
     mem_available = (uint64_t) sysconf (_SC_AVPHYS_PAGES) * sysconf (_SC_PAGESIZE);
+# else
+    mem_available = (uint64_t) sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
+# endif
 #endif
 
     default_tile_cache_size = mem_total;
