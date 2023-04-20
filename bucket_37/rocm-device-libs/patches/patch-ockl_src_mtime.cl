--- ockl/src/mtime.cl.orig	2022-11-04 13:01:30 UTC
+++ ockl/src/mtime.cl
@@ -14,12 +14,6 @@ mem_realtime(void)
     return __builtin_amdgcn_s_memrealtime();
 }
 
-__attribute__((target("gfx11-insts"))) static ulong
-msg_realtime(void)
-{
-    return __builtin_amdgcn_s_sendmsg_rtnl(0x83);
-}
-
 // Deprecated
 __attribute__((target("s-memtime-inst"))) ulong
 OCKL_MANGLE_U64(memtime)(void)
@@ -43,10 +37,6 @@ OCKL_MANGLE_U64(cyclectr)(void)
 ulong
 OCKL_MANGLE_U64(steadyctr)(void)
 {
-    if (__oclc_ISA_version >= 11000) {
-        return msg_realtime();
-    } else {
         return mem_realtime();
-    }
 }
 
