--- src/amdgpu_drm_queue.c.orig	2018-03-02 17:31:02 UTC
+++ src/amdgpu_drm_queue.c
@@ -62,7 +62,7 @@ amdgpu_drm_queue_handler(int fd, unsigne
 			 unsigned int usec, void *user_ptr)
 {
 	uintptr_t seq = (uintptr_t)user_ptr;
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->seq == seq) {
@@ -134,7 +134,7 @@ amdgpu_drm_abort_one(struct amdgpu_drm_q
 void
 amdgpu_drm_abort_client(ClientPtr client)
 {
-	struct amdgpu_drm_queue_entry *e;
+	struct amdgpu_drm_queue_entry *e = NULL;
 
 	xorg_list_for_each_entry(e, &amdgpu_drm_queue, list) {
 		if (e->client == client)
@@ -148,7 +148,7 @@ amdgpu_drm_abort_client(ClientPtr client
 void
 amdgpu_drm_abort_entry(uintptr_t seq)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->seq == seq) {
@@ -164,7 +164,7 @@ amdgpu_drm_abort_entry(uintptr_t seq)
 void
 amdgpu_drm_abort_id(uint64_t id)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->id == id) {
@@ -192,7 +192,7 @@ amdgpu_drm_queue_init()
 void
 amdgpu_drm_queue_close(ScrnInfoPtr scrn)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->crtc->scrn == scrn)
