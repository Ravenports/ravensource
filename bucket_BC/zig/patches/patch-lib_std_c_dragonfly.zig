--- lib/std/c/dragonfly.zig.orig	2024-06-06 19:05:11 UTC
+++ lib/std/c/dragonfly.zig
@@ -563,6 +563,33 @@ pub const NOTE_FFCTRLMASK = 3221225472;
 pub const NOTE_FFCOPY = 3221225472;
 pub const NOTE_PCTRLMASK = 4026531840;
 
+pub const T = struct {
+    pub const IOCEXCL = 0x2000740d;
+    pub const IOCNXCL = 0x2000740e;
+    pub const IOCSCTTY = 0x20007461;
+    pub const IOCGPGRP = 0x40047477;
+    pub const IOCSPGRP = 0x80047476;
+    pub const IOCOUTQ = 0x40047473;
+    pub const IOCSTI = 0x80017472;
+    pub const IOCGWINSZ = 0x40087468;
+    pub const IOCSWINSZ = 0x80087467;
+    pub const IOCMGET = 0x4004746a;
+    pub const IOCMBIS = 0x8004746c;
+    pub const IOCMBIC = 0x8004746b;
+    pub const IOCMSET = 0x8004746d;
+    pub const FIONREAD = 0x4004667f;
+    pub const IOCCONS = 0x80047462;
+    pub const IOCPKT = 0x80047470;
+    pub const FIONBIO = 0x8004667e;
+    pub const IOCNOTTY = 0x20007471;
+    pub const IOCSETD = 0x8004741b;
+    pub const IOCGETD = 0x4004741a;
+    pub const IOCSBRK = 0x2000747b;
+    pub const IOCCBRK = 0x2000747a;
+    pub const IOCGSID = 0x40047463;
+    pub const IOCSIG = 0x2004745f;
+};
+
 pub const TCSA = enum(c_uint) {
     NOW,
     DRAIN,
@@ -570,6 +597,13 @@ pub const TCSA = enum(c_uint) {
     _,
 };
 
+pub const winsize = extern struct {
+    ws_row: u16,
+    ws_col: u16,
+    ws_xpixel: u16,
+    ws_ypixel: u16,
+};
+
 pub const stack_t = extern struct {
     sp: [*]u8,
     size: isize,
