--- ../zig-0.4.0.orig/src/zig_llvm.cpp	2019-04-09 01:30:42.000000000 +0300
+++ src/zig_llvm.cpp	2019-04-29 23:23:24.829139000 +0300
@@ -883,6 +883,7 @@
             break;
         case ZigLLVM_OpenBSD:
         case ZigLLVM_FreeBSD:
+        case ZigLLVM_DragonFly:
             kind = object::Archive::K_BSD;
             break;
         default:
