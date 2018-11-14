--- gdb/compile/compile-loc2c.c.orig	2018-09-05 07:44:28 UTC
+++ gdb/compile/compile-loc2c.c
@@ -656,6 +656,7 @@ do_compile_dwarf_expr_to_c (int indent,
       uint64_t uoffset, reg;
       int64_t offset;
 
+      uoffset = 0;
       print_spaces (indent - 2, &stream);
       if (info[op_ptr - base].label)
 	{
