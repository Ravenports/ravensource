--- src/luarocks/core/cfg.lua.orig	2022-12-08 20:13:08 UTC
+++ src/luarocks/core/cfg.lua
@@ -36,6 +36,7 @@ local platform_order = {
    "openbsd",
    "freebsd",
    "dragonfly",
+   "midnightbsd",
    "linux",
    "macosx",
    "cygwin",
@@ -151,6 +152,7 @@ local platform_sets = {
    freebsd = { unix = true, bsd = true, freebsd = true },
    openbsd = { unix = true, bsd = true, openbsd = true },
    dragonfly = { unix = true, bsd = true, dragonfly = true },
+   midnightbsd = { unix = true, bsd = true, midnightbsd = true },
    solaris = { unix = true, solaris = true },
    windows = { windows = true, win32 = true },
    cygwin = { unix = true, cygwin = true },
@@ -521,6 +523,8 @@ local function make_defaults(lua_version
       defaults.arch = "openbsd-"..target_cpu
    elseif platforms.netbsd then
       defaults.arch = "netbsd-"..target_cpu
+   elseif platforms.midnightbsd then
+      defaults.arch = "midnightbsd-"..target_cpu
    elseif platforms.solaris then
       defaults.arch = "solaris-"..target_cpu
       defaults.variables.MAKE = "gmake"
