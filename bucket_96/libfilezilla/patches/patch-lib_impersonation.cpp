--- lib/impersonation.cpp.orig	2026-11-13 18:30:59 UTC
+++ lib/impersonation.cpp
@@ -81,7 +81,11 @@ impersonation_token::impersonation_token
 
 #include "libfilezilla/buffer.hpp"
 
-#if FZ_UNIX
+#if defined(__linux__)
+#define SHADOW_SUPPORTED
+#endif
+
+#ifdef SHADOW_SUPPORTED
 #include <crypt.h>
 #include <shadow.h>
 #endif
@@ -177,7 +181,7 @@ std::optional<gid_t> get_group(native_st
 	return {};
 }
 
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -265,7 +269,7 @@ std::vector<gid_t> get_supplementary(std
 
 bool check_auth(native_string const& username, native_string const& password)
 {
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 	auto shadow = get_shadow(username);
 	if (shadow.shadow_) {
 		struct crypt_data data{};
