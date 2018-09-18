--- gold/x86_64.cc.orig	2018-06-24 18:38:57 UTC
+++ gold/x86_64.cc
@@ -1400,7 +1400,7 @@ const Target::Target_info Target_x86_64<
   true,			// is_default_stack_executable
   true,			// can_icf_inline_merge_sections
   '\0',			// wrap_char
-  "/lib/ld64.so.1",     // program interpreter
+  "@ELF64_INTERPRETER@",     // program interpreter
   0x400000,		// default_text_segment_address
   0x1000,		// abi_pagesize (overridable by -z max-page-size)
   0x1000,		// common_pagesize (overridable by -z common-page-size)
@@ -1429,7 +1429,7 @@ const Target::Target_info Target_x86_64<
   true,			// is_default_stack_executable
   true,			// can_icf_inline_merge_sections
   '\0',			// wrap_char
-  "/libx32/ldx32.so.1", // program interpreter
+  "@ELF32_INTERPRETER@", // program interpreter
   0x400000,		// default_text_segment_address
   0x1000,		// abi_pagesize (overridable by -z max-page-size)
   0x1000,		// common_pagesize (overridable by -z common-page-size)
