--- Foundation/src/File_UNIX.cpp.orig	2025-05-12 09:00:11 UTC
+++ Foundation/src/File_UNIX.cpp
@@ -255,7 +255,7 @@ Timestamp FileImpl::getLastModifiedImpl(
 	struct stat st;
 	if (::stat(_path.c_str(), &st) == 0)
 	{
-#if defined(__FreeBSD__) || (defined(__APPLE__) && defined(_DARWIN_FEATURE_64_BIT_INODE))
+#if defined(__FreeBSD__) || defined(__DragonFly__) || (defined(__APPLE__) && defined(_DARWIN_FEATURE_64_BIT_INODE))
 		const TV tv = static_cast<TV>(st.st_mtimespec.tv_sec) * Timestamp::resolution() + st.st_mtimespec.tv_nsec/nsk;
 		return Timestamp(tv);
 #elif POCO_OS == POCO_OS_LINUX
