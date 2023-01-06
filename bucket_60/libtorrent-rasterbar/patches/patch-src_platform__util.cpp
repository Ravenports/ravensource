--- src/platform_util.cpp.orig	2022-10-23 11:27:37 UTC
+++ src/platform_util.cpp
@@ -40,7 +40,7 @@ POSSIBILITY OF SUCH DAMAGE.
 
 #if TORRENT_HAS_PTHREAD_SET_NAME
 #include <pthread.h>
-#ifdef TORRENT_BSD
+#if defined(TORRENT_BSD) && !defined(__NetBSD__)
 #include <pthread_np.h>
 #endif
 #endif
@@ -105,7 +105,11 @@ namespace libtorrent {
 		TORRENT_UNUSED(name);
 #if TORRENT_HAS_PTHREAD_SET_NAME
 #ifdef TORRENT_BSD
+# if defined(__NetBSD__)
+		pthread_setname_np(pthread_self(), name, nullptr);
+# else
 		pthread_set_name_np(pthread_self(), name);
+# endif
 #else
 		pthread_setname_np(pthread_self(), name);
 #endif
