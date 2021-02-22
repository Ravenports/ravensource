--- include/libtorrent/aux_/buffer.hpp.orig	2021-01-07 22:53:40 UTC
+++ include/libtorrent/aux_/buffer.hpp
@@ -52,7 +52,7 @@ POSSIBILITY OF SUCH DAMAGE.
 #include <malloc.h>
 #elif defined __FreeBSD__
 #include <malloc_np.h>
-#elif defined TORRENT_BSD
+#elif defined TORRENT_BSD && !defined(__DragonFly__)
 #include <malloc/malloc.h>
 #endif
 
@@ -93,7 +93,7 @@ public:
 		m_size = static_cast<difference_type>(::malloc_usable_size(m_begin));
 #elif defined _MSC_VER
 		m_size = static_cast<difference_type>(::_msize(m_begin));
-#elif defined TORRENT_BSD
+#elif defined TORRENT_BSD && !defined(__DragonFly__)
 		m_size = static_cast<difference_type>(::malloc_size(m_begin));
 #else
 		m_size = size;
