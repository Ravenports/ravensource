--- src/pipewire/buffers.c.orig	2025-06-27 11:16:18 UTC
+++ src/pipewire/buffers.c
@@ -48,7 +48,7 @@ static int alloc_buffers(struct pw_mempo
 	if (!SPA_FLAG_IS_SET(flags, PW_BUFFERS_FLAG_SHARED))
 		SPA_FLAG_SET(info.flags, SPA_BUFFER_ALLOC_FLAG_INLINE_ALL);
 
-	datas = alloca(sizeof(struct spa_data) * n_datas);
+	datas = __builtin_alloca(sizeof(struct spa_data) * n_datas);
 
 	for (i = 0; i < n_datas; i++) {
 		struct spa_data *d = &datas[i];
@@ -221,10 +221,10 @@ int pw_buffers_negotiate(struct pw_conte
 	if ((res = param_filter(result, &input, &output, SPA_PARAM_Meta, &b)) > 0)
 		n_params += res;
 
-	metas = alloca(sizeof(struct spa_meta) * n_params);
+	metas = __builtin_alloca(sizeof(struct spa_meta) * n_params);
 
 	n_metas = 0;
-	params = alloca(n_params * sizeof(struct spa_pod *));
+	params = __builtin_alloca(n_params * sizeof(struct spa_pod *));
 	for (i = 0, offset = 0; i < n_params; i++) {
 		uint32_t type, size;
 
@@ -318,10 +318,10 @@ int pw_buffers_negotiate(struct pw_conte
 	if (SPA_FLAG_IS_SET(flags, PW_BUFFERS_FLAG_NO_MEM))
 		minsize = 0;
 
-	data_sizes = alloca(sizeof(uint32_t) * blocks);
-	data_strides = alloca(sizeof(int32_t) * blocks);
-	data_aligns = alloca(sizeof(uint32_t) * blocks);
-	data_types = alloca(sizeof(uint32_t) * blocks);
+	data_sizes = __builtin_alloca(sizeof(uint32_t) * blocks);
+	data_strides = __builtin_alloca(sizeof(int32_t) * blocks);
+	data_aligns = __builtin_alloca(sizeof(uint32_t) * blocks);
+	data_types = __builtin_alloca(sizeof(uint32_t) * blocks);
 
 	for (i = 0; i < blocks; i++) {
 		data_sizes[i] = minsize;
