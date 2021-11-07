--- gdb/compile/compile-loc2c.c.orig	2021-09-13 01:32:09 UTC
+++ gdb/compile/compile-loc2c.c
@@ -674,6 +674,7 @@ do_compile_dwarf_expr_to_c (int indent,
       uint64_t uoffset, reg;
       int64_t offset;
 
+      uoffset = 0;
       print_spaces (indent - 2, stream);
       if (info[op_ptr - base].label)
 	{
