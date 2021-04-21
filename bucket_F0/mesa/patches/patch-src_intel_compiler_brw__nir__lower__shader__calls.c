--- src/intel/compiler/brw_nir_lower_shader_calls.c.orig	2021-04-21 17:41:10 UTC
+++ src/intel/compiler/brw_nir_lower_shader_calls.c
@@ -151,15 +151,15 @@ instr_is_shader_call(nir_instr *instr)
           intrin->intrinsic == nir_intrinsic_execute_callable;
 }
 
-struct bitset {
+struct mesa_bitset {
    BITSET_WORD *set;
    unsigned size;
 };
 
-static struct bitset
+static struct mesa_bitset
 bitset_create(void *mem_ctx, unsigned size)
 {
-   return (struct bitset) {
+   return (struct mesa_bitset) {
       .set = rzalloc_array(mem_ctx, BITSET_WORD, BITSET_WORDS(size)),
       .size = size,
    };
@@ -168,7 +168,7 @@ bitset_create(void *mem_ctx, unsigned si
 static bool
 src_is_in_bitset(nir_src *src, void *_set)
 {
-   struct bitset *set = _set;
+   struct mesa_bitset *set = _set;
    assert(src->is_ssa);
 
    /* Any SSA values which were added after we generated liveness information
@@ -183,7 +183,7 @@ src_is_in_bitset(nir_src *src, void *_se
 }
 
 static void
-add_ssa_def_to_bitset(nir_ssa_def *def, struct bitset *set)
+add_ssa_def_to_bitset(nir_ssa_def *def, struct mesa_bitset *set)
 {
    if (def->index >= set->size)
       return;
@@ -192,7 +192,7 @@ add_ssa_def_to_bitset(nir_ssa_def *def,
 }
 
 static bool
-can_remat_instr(nir_instr *instr, struct bitset *remat)
+can_remat_instr(nir_instr *instr, struct mesa_bitset *remat)
 {
    /* Set of all values which are trivially re-materializable and we shouldn't
     * ever spill them.  This includes:
@@ -270,7 +270,7 @@ can_remat_instr(nir_instr *instr, struct
 }
 
 static bool
-can_remat_ssa_def(nir_ssa_def *def, struct bitset *remat)
+can_remat_ssa_def(nir_ssa_def *def, struct mesa_bitset *remat)
 {
    return can_remat_instr(def->parent_instr, remat);
 }
@@ -362,7 +362,7 @@ spill_ssa_defs_and_lower_shader_calls(ni
 
    const unsigned num_ssa_defs = impl->ssa_alloc;
    const unsigned live_words = BITSET_WORDS(num_ssa_defs);
-   struct bitset trivial_remat = bitset_create(mem_ctx, num_ssa_defs);
+   struct mesa_bitset trivial_remat = bitset_create(mem_ctx, num_ssa_defs);
 
    /* Array of all live SSA defs which are spill candidates */
    nir_ssa_def **spill_defs =
@@ -434,7 +434,7 @@ spill_ssa_defs_and_lower_shader_calls(ni
          /* Make a copy of trivial_remat that we'll update as we crawl through
           * the live SSA defs and unspill them.
           */
-         struct bitset remat = bitset_create(mem_ctx, num_ssa_defs);
+         struct mesa_bitset remat = bitset_create(mem_ctx, num_ssa_defs);
          memcpy(remat.set, trivial_remat.set, live_words * sizeof(BITSET_WORD));
 
          /* Before the two builders are always separated by the call
@@ -926,7 +926,7 @@ flatten_resume_if_ladder(nir_function_im
                          struct exec_list *child_list,
                          bool child_list_contains_cursor,
                          nir_instr *resume_instr,
-                         struct bitset *remat)
+                         struct mesa_bitset *remat)
 {
    nir_shader *shader = impl->function->shader;
    nir_cf_list cf_list;
@@ -1113,7 +1113,7 @@ lower_resume(nir_shader *shader, int cal
    /* Used to track which things may have been assumed to be re-materialized
     * by the spilling pass and which we shouldn't delete.
     */
-   struct bitset remat = bitset_create(mem_ctx, impl->ssa_alloc);
+   struct mesa_bitset remat = bitset_create(mem_ctx, impl->ssa_alloc);
 
    /* Create a nop instruction to use as a cursor as we extract and re-insert
     * stuff into the CFG.
