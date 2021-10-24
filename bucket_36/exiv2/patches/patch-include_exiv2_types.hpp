$NetBSD: patch-include_exiv2_types.hpp,v 1.1 2018/01/29 09:58:34 jperkin Exp $

Remove bogus forward declaration.

--- include/exiv2/types.hpp.orig	2021-06-15 14:08:36 UTC
+++ include/exiv2/types.hpp
@@ -81,7 +81,6 @@
 
 // *****************************************************************************
 // forward declarations
-struct tm;
 
 // *****************************************************************************
 // namespace extensions
