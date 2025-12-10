--- amdgpu/amdgpu_asic_id.c.orig	2025-12-08 13:15:17 UTC
+++ amdgpu/amdgpu_asic_id.c
@@ -236,7 +236,11 @@ static void split_env_var_free(char **sp
 static char *find_asic_id_table(void)
 {
 	// first check the paths in AMDGPU_ASIC_ID_TABLE_PATHS environment variable
+#if defined(__DragonFly__)
+	const char *amdgpu_asic_id_table_paths = getenv("AMDGPU_ASIC_ID_TABLE_PATHS");
+#else
 	const char *amdgpu_asic_id_table_paths = secure_getenv("AMDGPU_ASIC_ID_TABLE_PATHS");
+#endif
 	char *file_name = NULL;
 	char *found_path = NULL;
 	char **paths = NULL;
