--- gdb/compile/compile-loc2c.c.orig	2022-01-16 11:21:18 UTC
+++ gdb/compile/compile-loc2c.c
@@ -674,6 +674,7 @@ do_compile_dwarf_expr_to_c (int indent,
       uint64_t uoffset, reg;
       int64_t offset;
 
+      uoffset = 0;
       print_spaces (indent - 2, stream);
       if (info[op_ptr - base].label)
 	{
