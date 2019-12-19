# Fix error: no matching constructor for initialization of 'std::vector<const ::llvm::MDNode *>' 
#
--- src/gallium/state_trackers/clover/llvm/metadata.hpp.orig	2019-12-18 19:04:21 UTC
+++ src/gallium/state_trackers/clover/llvm/metadata.hpp
@@ -42,7 +42,7 @@ namespace clover {
          get_kernel_nodes(const ::llvm::Module &mod) {
             if (const ::llvm::NamedMDNode *n =
                    mod.getNamedMetadata("opencl.kernels"))
-               return { n->op_begin(), n->op_end() };
+               return { n->getOperand(0), n->getOperand(n->getNumOperands()) };
             else
                return {};
          }
