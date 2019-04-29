--- ../zig-0.4.0.orig/src/link.cpp	2019-04-09 01:30:42.000000000 +0300
+++ src/link.cpp	2019-04-29 22:23:30.505394000 +0300
@@ -872,7 +872,7 @@
                 return "elf32_x86_64";
             }
             // Any target elf will use the freebsd osabi if suffixed with "_fbsd".
-            if (t->os == OsFreeBSD) {
+            if (t->os == OsFreeBSD || t->os == OsDragonFly) {
                 return "elf_x86_64_fbsd";
             }
             return "elf_x86_64";
@@ -1043,6 +1043,17 @@
                 lj->args.append("-lm");
                 lj->args.append("--end-group");
             } else {
+                if (g->zig_target->os == OsDragonFly) {
+                    // path to libgcc.a
+                    lj->args.append(
+                        "-L/raven/share/raven/toolchain/gcc8/lib/gcc/x86_64-raven-dragonfly5.4/8.3.0");
+                    // path to libgcc_s.so
+                    lj->args.append(
+                        "-L/raven/share/raven/toolchain/gcc8/lib");
+                    // prefer .a over .so
+                    // fixes: lld: warning: found local symbol '__thread_locale' in global part of symbol table in file /raven/share/raven/sysroot/DragonFly/usr/lib/libc.so
+                    lj->args.append("/raven/share/raven/sysroot/DragonFly/usr/lib/libc.a");
+                }
                 lj->args.append("-lgcc");
                 lj->args.append("--as-needed");
                 lj->args.append("-lgcc_s");
