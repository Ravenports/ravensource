From e34ec7de5964baa214555115f5061ed199d0f7b4 Mon Sep 17 00:00:00 2001
From: Daniel Stenberg <daniel@haxx.se>
Date: Wed, 11 Sep 2019 23:11:58 +0200
Subject: [PATCH] asyn-thread: s/AF_LOCAL/AF_UNIX for Solaris

Reported-by: Dagobert Michelsen
Fixes #4328
Closes #4333
---
 lib/asyn-thread.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/lib/asyn-thread.c b/lib/asyn-thread.c
index 24da748850..fcbf1305ef 100755
--- lib/asyn-thread.c
+++ lib/asyn-thread.c
@@ -244,8 +244,8 @@ int init_thread_sync_data(struct thread_data * td,
   Curl_mutex_init(tsd->mtx);
 
 #ifdef HAVE_SOCKETPAIR
-  /* create socket pair */
-  if(socketpair(AF_LOCAL, SOCK_STREAM, 0, &tsd->sock_pair[0]) < 0) {
+  /* create socket pair, avoid AF_LOCAL since it doesn't build on Solaris */
+  if(socketpair(AF_UNIX, SOCK_STREAM, 0, &tsd->sock_pair[0]) < 0) {
     tsd->sock_pair[0] = CURL_SOCKET_BAD;
     tsd->sock_pair[1] = CURL_SOCKET_BAD;
     goto err_exit;
