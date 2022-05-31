--- lib/impersonation.cpp.orig	2022-04-01 12:35:07 UTC
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
@@ -79,7 +83,7 @@ std::optional<gid_t> get_group(fz::nativ
 	return {};
 }
 
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -171,7 +175,7 @@ std::vector<gid_t> get_supplementary(std
 
 bool check_auth(fz::native_string const& username, fz::native_string const& password)
 {
-#if FZ_UNIX
+#ifdef SHADOW_SUPPORTED
 	auto shadow = get_shadow(username);
 	if (shadow.shadow_) {
 		struct crypt_data data{};
@@ -217,6 +221,7 @@ bool check_auth(fz::native_string const&
 impersonation_token::impersonation_token(fz::native_string const& username, fz::native_string const& password)
 {
 	auto pwd = get_passwd(username);
+#ifdef SHADOW_SUPPORTED
 	if (pwd.pwd_) {
 		if (check_auth(username, password)) {
 			impl_ = std::make_unique<impersonation_token_impl>();
@@ -229,6 +234,22 @@ impersonation_token::impersonation_token
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
 
 impersonation_token::impersonation_token(fz::native_string const& username, impersonation_flag flag, fz::native_string const& group)
