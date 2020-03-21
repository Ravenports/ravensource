--- compat/cpuset.c.orig	2020-03-17 10:00:17 UTC
+++ compat/cpuset.c
@@ -13,7 +13,7 @@
 #include <unistd.h>
 
 #ifndef HAVE_CPUSET_CREATE
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 cpuset_t *cpuset_create(void)
 {
   cpuset_t *set = calloc(1, sizeof(*set));
@@ -23,7 +23,7 @@ cpuset_t *cpuset_create(void)
 #endif /* !HAVE_CPUSET_CREATE */
 
 #ifndef HAVE_CPUSET_DESTROY
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 void cpuset_destroy(cpuset_t *set)
 {
   free(set);
@@ -32,7 +32,7 @@ void cpuset_destroy(cpuset_t *set)
 #endif /* !HAVE_CPUSET_DESTROY */
 
 #ifndef HAVE_CPUSET_ZERO
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 void cpuset_zero(cpuset_t *set)
 {
   CPU_ZERO(set);
@@ -41,7 +41,7 @@ void cpuset_zero(cpuset_t *set)
 #endif /* !HAVE_CPUSET_ZERO */
 
 #ifndef HAVE_CPUSET_SET
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 int cpuset_set(cpuid_t cpu, cpuset_t *set)
 {
   CPU_SET(cpu, set);
@@ -51,7 +51,7 @@ int cpuset_set(cpuid_t cpu, cpuset_t *se
 #endif /* !HAVE_CPUSET_SET */
 
 #ifndef HAVE_CPUSET_CLR
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 int cpuset_clr(cpuid_t cpu, cpuset_t *set)
 {
   CPU_CLR(cpu, set);
@@ -61,7 +61,7 @@ int cpuset_clr(cpuid_t cpu, cpuset_t *se
 #endif /* !HAVE_CPUSET_CLR */
 
 #ifndef HAVE_CPUSET_ISSET
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 int cpuset_isset(cpuid_t cpu, const cpuset_t *set)
 {
   return CPU_ISSET(cpu, set);
@@ -70,7 +70,7 @@ int cpuset_isset(cpuid_t cpu, const cpus
 #endif /* !HAVE_CPUSET_ISSET */
 
 #ifndef HAVE_CPUSET_SIZE
-#if __linux__ || __FreeBSD__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 size_t cpuset_size(const cpuset_t *set)
 {
   return sizeof(*set);
@@ -78,13 +78,13 @@ size_t cpuset_size(const cpuset_t *set)
 #endif
 #endif /* !HAVE_CPUSET_SIZE */
 
-#if __linux__
+#if defined(__linux__) || defined(__DragonFly__)
 void cpuset_or(cpuset_t *destset, const cpuset_t *srcset)
 {
   CPU_OR(destset, destset, srcset);
 }
 #endif
-#if __FreeBSD__
+#if defined(__FreeBSD__)
 void cpuset_or(cpuset_t *destset, const cpuset_t *srcset)
 {
   CPU_OR(destset, srcset);
