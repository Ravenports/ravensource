--- lib/impersonation.cpp.orig	2023-06-28 13:00:47 UTC
+++ lib/impersonation.cpp
@@ -7,7 +7,11 @@
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
@@ -98,7 +102,7 @@ std::optional<gid_t> get_group(native_st
 	return {};
 }
 
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -190,7 +194,7 @@ std::vector<gid_t> get_supplementary(std
 
 bool check_auth(native_string const& username, native_string const& password)
 {
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 	auto shadow = get_shadow(username);
 	if (shadow.shadow_) {
 		struct crypt_data data{};
@@ -236,6 +240,7 @@ bool check_auth(native_string const& use
 impersonation_token::impersonation_token(native_string const& username, native_string const& password)
 {
 	auto pwd = get_passwd(username);
+#ifdef SHADOW_SUPPORTED
 	if (pwd.pwd_) {
 		if (check_auth(username, password)) {
 			impl_ = std::make_unique<impersonation_token_impl>();
@@ -248,6 +253,22 @@ impersonation_token::impersonation_token
 			impl_->sup_groups_ = get_supplementary(username, pwd.pwd_->pw_gid);
 		}
 	}
+#else
+	char *c;
+	if (pwd.pwd_) {
+		c = crypt(password.c_str(), pwd.pwd_->pw_passwd);
+		if ((c != NULL) && (strcmp(c, pwd.pwd_->pw_passwd) == 0)) {
+			impl_ = std::make_unique<impersonation_token_impl>();
+			impl_->name_ = username;
+			if (pwd.pwd_->pw_dir) {
+				impl_->home_ = pwd.pwd_->pw_dir;
+			}
+			impl_->uid_ = pwd.pwd_->pw_uid;
+			impl_->gid_ = pwd.pwd_->pw_gid;
+			impl_->sup_groups_ = get_supplementary(username, pwd.pwd_->pw_gid);
+		}
+	}
+#endif    /* SHADOW_SUPPORTED */
 }
 
 impersonation_token::impersonation_token(native_string const& username, impersonation_flag flag, native_string const& group)
