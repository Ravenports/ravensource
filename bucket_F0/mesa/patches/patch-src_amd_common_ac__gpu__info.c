--- src/amd/common/ac_gpu_info.c.orig	2026-08-12 15:22:27 UTC
+++ src/amd/common/ac_gpu_info.c
@@ -85,7 +85,7 @@ static void set_custom_cu_en_mask(struct
       return;
 
    int size = strlen(cu_env_var);
-   char *str = alloca(size + 1);
+   char *str = __builtin_alloca(size + 1);
    memset(str, 0, size + 1);
 
    size = 0;
