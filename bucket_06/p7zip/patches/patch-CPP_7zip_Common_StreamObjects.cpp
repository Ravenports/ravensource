CVE-2021-3465.patch

--- CPP/7zip/Common/StreamObjects.cpp.orig	2015-06-19 10:52:08 UTC
+++ CPP/7zip/Common/StreamObjects.cpp
@@ -157,6 +157,8 @@ STDMETHODIMP CDynBufSeqOutStream::Write(
 
 STDMETHODIMP CBufPtrSeqOutStream::Write(const void *data, UInt32 size, UInt32 *processedSize)
 {
+  if(_buffer == nullptr || _size == _pos)
+    return E_FAIL;
   size_t rem = _size - _pos;
   if (rem > size)
     rem = (size_t)size;
