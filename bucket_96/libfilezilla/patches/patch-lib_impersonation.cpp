--- lib/impersonation.cpp.orig	2025-03-26 10:07:26 UTC
+++ lib/impersonation.cpp
@@ -27,7 +27,11 @@ impersonation_token::impersonation_token
 #include <optional>
 #include <tuple>
 
-#if FZ_UNIX
+#if defined(__linux__)
+#define SHADOW_SUPPORTED
+#endif
+
+#ifdef SHADOW_SUPPORTED
 #include <crypt.h>
 #include <shadow.h>
 #endif
@@ -118,7 +122,7 @@ std::optional<gid_t> get_group(native_st
 	return {};
 }
 
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -203,7 +207,7 @@ std::vector<gid_t> get_supplementary(std
 
 bool check_auth(native_string const& username, native_string const& password)
 {
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 	auto shadow = get_shadow(username);
 	if (shadow.shadow_) {
 		struct crypt_data data{};
