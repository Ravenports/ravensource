--- lib/impersonation.cpp.orig	2021-10-19 09:51:29 UTC
+++ lib/impersonation.cpp
@@ -7,10 +7,16 @@
 #include <optional>
 #include <tuple>
 
+#if defined(__linux__)
+#define SHADOW_SUPPORTED
+#endif
+
+#ifdef SHADOW_SUPPORTED
 #include <crypt.h>
+#include <shadow.h>
+#endif
 #include <grp.h>
 #include <pwd.h>
-#include <shadow.h>
 #include <string.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -53,6 +59,7 @@ passwd_holder get_passwd(fz::native_stri
 }
 
 
+#ifdef SHADOW_SUPPORTED
 struct shadow_holder {
 	shadow_holder() = default;
 	shadow_holder(shadow_holder const&) = delete;
@@ -87,6 +94,7 @@ shadow_holder get_shadow(fz::native_stri
 
 	return ret;
 }
+#endif    /* SHADOW_SUPPORTED */
 }
 
 class impersonation_token_impl final
@@ -138,6 +146,7 @@ std::vector<gid_t> get_supplementary(std
 impersonation_token::impersonation_token(fz::native_string const& username, fz::native_string const& passwd)
 {
 	auto pwd = get_passwd(username);
+#ifdef SHADOW_SUPPORTED
 	if (pwd.pwd_) {
 		auto shadow = get_shadow(username);
 		if (shadow.shadow_) {
@@ -155,6 +164,22 @@ impersonation_token::impersonation_token
 			}
 		}
 	}
+#else
+	char *c;
+	if (pwd.pwd_) {
+		c = crypt(passwd.c_str(), pwd.pwd_->pw_passwd);
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
 
 impersonation_token::impersonation_token(fz::native_string const& username, impersonation_flag flag)
