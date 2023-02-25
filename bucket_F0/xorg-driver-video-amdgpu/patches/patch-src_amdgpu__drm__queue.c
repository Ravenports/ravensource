--- src/amdgpu_drm_queue.c.orig	2022-02-23 12:27:54 UTC
+++ src/amdgpu_drm_queue.c
@@ -94,7 +94,7 @@ amdgpu_drm_queue_handler(int fd, unsigne
 			 unsigned int usec, void *user_ptr)
 {
 	uintptr_t seq = (uintptr_t)user_ptr;
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->seq == seq) {
@@ -213,7 +213,7 @@ amdgpu_drm_queue_alloc(xf86CrtcPtr crtc,
 void
 amdgpu_drm_abort_client(ClientPtr client)
 {
-	struct amdgpu_drm_queue_entry *e;
+	struct amdgpu_drm_queue_entry *e = NULL;
 
 	xorg_list_for_each_entry(e, &amdgpu_drm_queue, list) {
 		if (e->client == client)
@@ -227,7 +227,7 @@ amdgpu_drm_abort_client(ClientPtr client
 void
 amdgpu_drm_abort_entry(uintptr_t seq)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	if (seq == AMDGPU_DRM_QUEUE_ERROR)
 		return;
@@ -260,7 +260,7 @@ amdgpu_drm_abort_entry(uintptr_t seq)
 void
 amdgpu_drm_abort_id(uint64_t id)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->id == id) {
@@ -356,7 +356,7 @@ amdgpu_drm_queue_init(ScrnInfoPtr scrn)
 void
 amdgpu_drm_queue_close(ScrnInfoPtr scrn)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->crtc->scrn == scrn)
