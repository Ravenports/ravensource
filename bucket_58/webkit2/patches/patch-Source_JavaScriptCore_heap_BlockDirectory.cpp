--- Source/JavaScriptCore/heap/BlockDirectory.cpp.orig	2026-02-19 21:54:10 UTC
+++ Source/JavaScriptCore/heap/BlockDirectory.cpp
@@ -74,6 +74,7 @@ void BlockDirectory::updatePercentageOfP
     auto numberOfPagesInMarkedBlock = MarkedBlock::blockSize / pageSize;
     // For some reason this can be unsigned char or char on different OSes...
     using MincoreBufferType = std::remove_pointer_t<FunctionTraits<decltype(mincore)>::ArgumentType<2>>;
+    using MincoreAddressType = FunctionTraits<decltype(mincore)>::ArgumentType<0>;
     static_assert(std::is_same_v<std::make_unsigned_t<MincoreBufferType>, unsigned char>);
     Vector<MincoreBufferType, 16> pagedBits(numberOfPagesInMarkedBlock, MincoreBufferType { });
 
@@ -85,7 +86,7 @@ void BlockDirectory::updatePercentageOfP
         auto markedBlockSizeInBytes = handle->backingStorageSize();
         RELEASE_ASSERT(markedBlockSizeInBytes / pageSize <= numberOfPagesInMarkedBlock);
         // We could cache this in bulk (e.g. 25 MB chunks) but we haven't seen any data that it actually matters.
-        auto result = mincore(pageStart, markedBlockSizeInBytes, pagedBits.mutableSpan().data());
+        auto result = mincore(reinterpret_cast<MincoreAddressType>(pageStart), markedBlockSizeInBytes, pagedBits.mutableSpan().data());
         RELEASE_ASSERT(!result);
         constexpr unsigned pageIsResidentAndNotCompressed = 1;
         for (unsigned i = 0; i < numberOfPagesInMarkedBlock; ++i)
