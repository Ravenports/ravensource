--- src/lib/caching/ksdcmapping_p.h.orig	2026-03-07 20:29:56 UTC
+++ src/lib/caching/ksdcmapping_p.h
@@ -192,7 +192,11 @@ private:
             if (mapAddress != MAP_FAILED) {
                 // Successful mmap doesn't actually mean that whole range is readable so ensure it is
                 struct rlimit memlock;
+#ifdef RLIMIT_MEMLOCK
                 if (getrlimit(RLIMIT_MEMLOCK, &memlock) == 0 && memlock.rlim_cur >= 2) {
+#else
+	        if (true) { // On OmniOS, assume the limit is managed by resource controls
+#endif
                     // Half of limit in case something else has already locked some mem
                     uint lockSize = qMin(memlock.rlim_cur / 2, (rlim_t)size);
                     // Note that lockSize might be less than what we need to mmap
