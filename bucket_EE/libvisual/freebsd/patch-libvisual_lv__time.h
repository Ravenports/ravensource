--- libvisual/lv_time.h.orig	2017-12-25 23:33:06.188334000 +0100
+++ libvisual/lv_time.h	2017-12-25 23:33:46.023582000 +0100
@@ -101,7 +101,7 @@
  *
  * @return Nothing.
  */
-static inline void visual_timer_tsc_get (uint32_t *lo, uint32_t *hi)
+static lv_inline void visual_timer_tsc_get (uint32_t *lo, uint32_t *hi)
 {
 #if defined(VISUAL_ARCH_X86) || defined(VISUAL_ARCH_X86_64)
 	__asm __volatile
@@ -115,7 +115,7 @@
 }
 
 /* FIXME use uint64_t here, make sure type exists */
-static inline unsigned long long visual_timer_tsc_get_returned ()
+static lv_inline unsigned long long visual_timer_tsc_get_returned ()
 {
 	uint32_t lo, hi;
 
