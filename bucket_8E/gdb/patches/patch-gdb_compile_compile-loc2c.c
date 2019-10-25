--- gdb/compile/compile-loc2c.c.orig	2019-02-27 04:51:50 UTC
+++ gdb/compile/compile-loc2c.c
@@ -657,6 +657,7 @@ do_compile_dwarf_expr_to_c (int indent,
       uint64_t uoffset, reg;
       int64_t offset;
 
+      uoffset = 0;
       print_spaces (indent - 2, stream);
       if (info[op_ptr - base].label)
 	{
