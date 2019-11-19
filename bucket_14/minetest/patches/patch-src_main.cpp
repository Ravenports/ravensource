From 097e74492d2901da14236d03cb0b78360fa1dfbe Mon Sep 17 00:00:00 2001
From: Dmitry Marakasov <amdmi3@amdmi3.ru>
Date: Wed, 23 Oct 2019 20:27:11 +0300
Subject: [PATCH] Fix build issue due to conflicting s64 type definitions

See comment in irrlichttypes.h and https://sourceforge.net/p/irrlicht/bugs/433/
---
 src/main.cpp | 1 +
 1 file changed, 1 insertion(+)

--- src/main.cpp.orig	2019-10-12 13:48:58 UTC
+++ src/main.cpp
@@ -17,6 +17,7 @@ with this program; if not, write to the
 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
 
+#include "irrlichttypes.h" // must be included before anything irrlicht, see comment in the file
 #include "irrlicht.h" // createDevice
 #include "irrlichttypes_extrabloated.h"
 #include "chat_interface.h"
