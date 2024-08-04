--- common/jobs-unix.cc.orig	2024-06-27 05:04:26 UTC
+++ common/jobs-unix.cc
@@ -86,12 +86,13 @@ static SharedData *get_shared_data() {
                                         MAP_SHARED, shm_fd, 0);
   close(shm_fd);
 
+#if !defined(__NetBSD__)
   if (data->initialized.exchange(true) == false) {
     pthread_mutexattr_t mu_attr;
     pthread_mutexattr_init(&mu_attr);
     pthread_mutexattr_setpshared(&mu_attr, PTHREAD_PROCESS_SHARED);
 
-#ifndef __APPLE__
+#if defined(PTHREAD_MUTEX_ROBUST)
     pthread_mutexattr_setrobust(&mu_attr, PTHREAD_MUTEX_ROBUST);
 #endif
 
@@ -102,6 +103,7 @@ static SharedData *get_shared_data() {
     pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
     pthread_cond_init(&data->cond, &cond_attr);
   }
+#endif
   return data;
 }
 
@@ -126,7 +128,7 @@ void acquire_global_lock() {
   pthread_cond_t *cond = &shared_data->cond;
   int r = pthread_mutex_lock(mu);
 
-#ifndef __APPLE__
+#if defined(PTHREAD_MUTEX_ROBUST)
   // If the previous process got killed while holding the mutex, the
   // mutex has became inconsistent. We need to fix it in that case.
   if (r == EOWNERDEAD)
