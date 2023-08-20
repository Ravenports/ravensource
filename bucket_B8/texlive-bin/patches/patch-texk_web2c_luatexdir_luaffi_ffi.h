--- texk/web2c/luatexdir/luaffi/ffi.h.intermediate	2019-01-20 23:58:29 UTC
+++ texk/web2c/luatexdir/luaffi/ffi.h
@@ -62,6 +62,7 @@ struct jit;
 #define DASM_EXTERN(a,b,c,d) get_extern(a,b,c,d)
 
 #include "dynasm/dasm_proto.h"
+#include <complex.h>
 
 #if defined LUA_FFI_BUILD_AS_DLL
 # define EXPORT __declspec(dllexport)
