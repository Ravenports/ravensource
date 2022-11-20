--- src/polkitbackend/polkitbackendjsauthority.cpp.orig	2022-10-26 12:12:24 UTC
+++ src/polkitbackend/polkitbackendjsauthority.cpp
@@ -40,6 +40,46 @@
 #error "This code is not safe in SpiderMonkey exact stack rooting configurations"
 #endif
 
+#ifdef __sun__
+int
+getgrouplist(const char *uname, gid_t agroup, gid_t *groups, int *grpcnt)
+{
+	const struct group *grp;
+	int i, maxgroups, ngroups, ret;
+
+	ret = 0;
+	ngroups = 0;
+	maxgroups = *grpcnt;
+	groups ? groups[ngroups++] = agroup : ngroups++;
+	if (maxgroups > 1)
+		groups ? groups[ngroups++] = agroup : ngroups++;
+	setgrent();
+	while ((grp = getgrent()) != NULL) {
+		if (groups) {
+			for (i = 0; i < ngroups; i++) {
+				if (grp->gr_gid == groups[i])
+					goto skip;
+			}
+		}
+		for (i = 0; grp->gr_mem[i]; i++) {
+			if (!strcmp(grp->gr_mem[i], uname)) {
+				if (ngroups >= maxgroups) {
+					ret = -1;
+					break;
+				}
+				groups ? groups[ngroups++] = grp->gr_gid : ngroups++;
+				break;
+			}
+		}
+skip:
+		;
+	}
+	endgrent();
+	*grpcnt = ngroups;
+	return (ret);
+}
+#endif
+
 /**
  * SECTION:polkitbackendjsauthority
  * @title: PolkitBackendJsAuthority
@@ -639,7 +679,11 @@ subject_to_jsval (PolkitBackendJsAuthori
 
       if (getgrouplist (passwd->pw_name,
                         passwd->pw_gid,
+#ifdef __APPLE__
+			(int *)gids,
+#else
                         gids,
+#endif
                         &num_gids) < 0)
         {
           g_warning ("Error looking up groups for uid %d: %m", (gint) uid);
