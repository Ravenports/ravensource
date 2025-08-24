--- gold/x86_64.cc.orig	2025-02-02 00:00:00 UTC
+++ gold/x86_64.cc
@@ -1301,7 +1301,7 @@ const Target::Target_info Target_x86_64<
   true,			// is_default_stack_executable
   true,			// can_icf_inline_merge_sections
   '\0',			// wrap_char
-  "/lib/ld64.so.1",     // program interpreter
+  "@ELF64_INTERPRETER@",     // program interpreter
   0x400000,		// default_text_segment_address
   0x1000,		// abi_pagesize (overridable by -z max-page-size)
   0x1000,		// common_pagesize (overridable by -z common-page-size)
@@ -1330,7 +1330,7 @@ const Target::Target_info Target_x86_64<
   true,			// is_default_stack_executable
   true,			// can_icf_inline_merge_sections
   '\0',			// wrap_char
-  "/libx32/ldx32.so.1", // program interpreter
+  "@ELF32_INTERPRETER@", // program interpreter
   0x400000,		// default_text_segment_address
   0x1000,		// abi_pagesize (overridable by -z max-page-size)
   0x1000,		// common_pagesize (overridable by -z common-page-size)
