--- common/jobs-unix.cc.orig	2024-06-27 05:04:26 UTC
+++ common/jobs-unix.cc
@@ -91,7 +91,7 @@ static SharedData *get_shared_data() {
     pthread_mutexattr_init(&mu_attr);
     pthread_mutexattr_setpshared(&mu_attr, PTHREAD_PROCESS_SHARED);
 
-#ifndef __APPLE__
+#if defined(PTHREAD_MUTEX_ROBUST)
     pthread_mutexattr_setrobust(&mu_attr, PTHREAD_MUTEX_ROBUST);
 #endif
 
@@ -126,7 +126,7 @@ void acquire_global_lock() {
   pthread_cond_t *cond = &shared_data->cond;
   int r = pthread_mutex_lock(mu);
 
-#ifndef __APPLE__
+#if defined(PTHREAD_MUTEX_ROBUST)
   // If the previous process got killed while holding the mutex, the
   // mutex has became inconsistent. We need to fix it in that case.
   if (r == EOWNERDEAD)
