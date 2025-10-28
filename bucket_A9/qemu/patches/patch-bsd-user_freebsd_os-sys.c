--- bsd-user/freebsd/os-sys.c.orig	2025-10-08 20:50:33 UTC
+++ bsd-user/freebsd/os-sys.c
@@ -426,7 +426,9 @@ static abi_long do_freebsd_sysctl_oid(CP
             switch (snamep[1]) {
             case CTL_SYSCTL_NEXT:
             case CTL_SYSCTL_NAME2OID:
+#ifdef CTL_SYSCTL_NEXTNOSKIP
             case CTL_SYSCTL_NEXTNOSKIP:
+#endif
                 /*
                  * All of these return an OID array, so we need to convert to
                  * target.
@@ -439,7 +441,9 @@ static abi_long do_freebsd_sysctl_oid(CP
                 sysctl_oidfmt(holdp);
                 break;
             case CTL_SYSCTL_OIDDESCR:
+#ifdef CTL_SYSCTL_OIDLABEL
             case CTL_SYSCTL_OIDLABEL:
+#endif
             default:
                 /* Handle it based on the type */
                 h2g_old_sysctl(holdp, &holdlen, kind);
