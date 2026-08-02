Fix build on NetBSD 10 (and 11)

--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc.orig	2025-12-04 02:11:46 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.cc
@@ -377,7 +377,7 @@ void ElfMemImage::SymbolIterator::Update
   const ElfW(Versym) *version_symbol = image->GetVersym(index_);
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && ((_SYS_EXEC_ELF_H_ + 0) < 2)
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
