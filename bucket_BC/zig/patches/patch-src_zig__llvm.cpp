--- src/zig_llvm.cpp.orig	2019-04-08 19:41:41 UTC
+++ src/zig_llvm.cpp
@@ -883,6 +883,7 @@ bool ZigLLVMWriteArchive(const char *arc
             break;
         case ZigLLVM_OpenBSD:
         case ZigLLVM_FreeBSD:
+        case ZigLLVM_DragonFly:
             kind = object::Archive::K_BSD;
             break;
         default:
