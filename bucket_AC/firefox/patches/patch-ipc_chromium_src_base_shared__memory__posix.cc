--- ipc/chromium/src/base/shared_memory_posix.cc.orig	2023-08-03 14:46:56 UTC
+++ ipc/chromium/src/base/shared_memory_posix.cc
@@ -284,6 +284,11 @@ bool SharedMemory::AppendPosixShmPrefix(
     StringAppendF(str, "snap.%s.", snap);
   }
 #  endif  // XP_LINUX
+#  ifdef OS_DRAGONFLY
+  // DragonFly BSD has a userland IPC implementation, we need to prefix the
+  // path to shm_open(3), preferably with '/tmp'
+  StringAppendF(str, "tmp/");
+#  endif
   // Hopefully the "implementation defined" name length limit is long
   // enough for this.
   StringAppendF(str, "org.mozilla.ipc.%d.", static_cast<int>(pid));
