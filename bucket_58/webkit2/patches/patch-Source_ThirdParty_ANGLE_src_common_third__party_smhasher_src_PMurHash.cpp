--- Source/ThirdParty/ANGLE/src/common/third_party/smhasher/src/PMurHash.cpp.orig	2022-02-23 11:41:42 UTC
+++ Source/ThirdParty/ANGLE/src/common/third_party/smhasher/src/PMurHash.cpp
@@ -48,6 +48,9 @@ on big endian machines, or a byte-by-byt
 -----------------------------------------------------------------------------*/
 
 #include "PMurHash.h"
+#ifdef __sun
+#define __BYTE_ORDER __LITTLE_ENDIAN
+#endif
 #include <stdint.h>
 
 /* I used ugly type names in the header to avoid potential conflicts with
