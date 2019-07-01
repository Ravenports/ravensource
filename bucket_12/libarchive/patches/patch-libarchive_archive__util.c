--- libarchive/archive_util.c.orig	2019-06-12 21:05:16 UTC
+++ libarchive/archive_util.c
@@ -46,16 +46,16 @@ __FBSDID("$FreeBSD: head/lib/libarchive/
 #include <wincrypt.h>
 #endif
 #ifdef HAVE_ZLIB_H
-#include <zlib.h>
+#include "zlib.h"
 #endif
 #ifdef HAVE_LZMA_H
-#include <lzma.h>
+#include "lzma.h"
 #endif
 #ifdef HAVE_BZLIB_H
-#include <bzlib.h>
+#include "bzlib.h"
 #endif
 #ifdef HAVE_LZ4_H
-#include <lz4.h>
+#include "lz4.h"
 #endif
 
 #include "archive.h"
