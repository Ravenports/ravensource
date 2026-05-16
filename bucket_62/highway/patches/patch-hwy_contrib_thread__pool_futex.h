From 2a8e177868e1309b27608062de8772d9edc0d475 Mon Sep 17 00:00:00 2001
From: Jan Wassenberg <janwas@google.com>
Date: Mon, 27 Apr 2026 04:28:01 -0700
Subject: [PATCH] Fix FreeBSD futex build, fixes #3007, thanks @jbeich

PiperOrigin-RevId: 906275505
---
 hwy/contrib/thread_pool/futex.h | 5 ++---
 1 file changed, 2 insertions(+), 3 deletions(-)

--- hwy/contrib/thread_pool/futex.h.orig
+++ hwy/contrib/thread_pool/futex.h
@@ -184,13 +184,12 @@ static inline uint32_t BlockUntilDifferent(
 
 #elif HWY_OS_FREEBSD && !defined(HWY_DISABLE_FUTEX)  // >= 6.0
   // _umtx_op with UMTX_OP_WAIT_UINT_PRIVATE: process-private futex on FreeBSD.
-  volatile void* address =
-      const_cast<volatile void*>(static_cast<const volatile void*>(&current));
+  void* address = const_cast<void*>(static_cast<const void*>(&current));
   for (;;) {
     const uint32_t next = current.load(acq);
     if (next != prev) return next;
     const int ret = _umtx_op(address, UMTX_OP_WAIT_UINT_PRIVATE,
-                             static_cast<unsigned long>(prev), nullptr, nullptr);
+                             static_cast<u_long>(prev), nullptr, nullptr);
     if (ret == -1) {
       HWY_DASSERT(errno == EAGAIN || errno == EINTR);
     }
