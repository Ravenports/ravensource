Breaks build when darktable not build with OpenMP

--- src/common/darktable.c.orig	2025-06-15 16:52:40 UTC
+++ src/common/darktable.c
@@ -1185,9 +1185,6 @@ int dt_init(int argc, char *argv[], cons
           dt_print(DT_DEBUG_ALWAYS,
                    "[dt_init --threads] requested %d ompthreads restricted to %d",
             desired, possible);
-        dt_print(DT_DEBUG_ALWAYS,
-                 "[dt_init --threads] using %d threads of %d for openmp parallel sections %s",
-          darktable.num_openmp_threads, (int)dt_get_num_procs(), omp_get_dynamic() ? "(dynamic)" : "(static)");
         k++;
         argv[k-1] = NULL;
         argv[k] = NULL;
