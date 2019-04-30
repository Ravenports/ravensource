--- ../zig-0.4.0.orig/std/event/fs.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/event/fs.zig	2019-04-26 16:00:38.105375000 +0300
@@ -86,6 +86,7 @@
         builtin.Os.linux,
         builtin.Os.freebsd,
         builtin.Os.netbsd,
+        builtin.Os.dragonfly,
         => {
             const iovecs = try loop.allocator.alloc(os.posix.iovec_const, data.len);
             defer loop.allocator.free(iovecs);
@@ -224,6 +225,7 @@
         builtin.Os.linux,
         builtin.Os.freebsd,
         builtin.Os.netbsd,
+        builtin.Os.dragonfly,
         => {
             const iovecs = try loop.allocator.alloc(os.posix.iovec, data.len);
             defer loop.allocator.free(iovecs);
@@ -404,7 +406,7 @@
 
 pub async fn openRead(loop: *Loop, path: []const u8) os.File.OpenError!os.FileHandle {
     switch (builtin.os) {
-        builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => {
+        builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
             const flags = posix.O_LARGEFILE | posix.O_RDONLY | posix.O_CLOEXEC;
             return await (async openPosix(loop, path, flags, os.File.default_mode) catch unreachable);
         },
@@ -434,6 +436,7 @@
         builtin.Os.linux,
         builtin.Os.freebsd,
         builtin.Os.netbsd,
+        builtin.Os.dragonfly,
         => {
             const flags = posix.O_LARGEFILE | posix.O_WRONLY | posix.O_CREAT | posix.O_CLOEXEC | posix.O_TRUNC;
             return await (async openPosix(loop, path, flags, os.File.default_mode) catch unreachable);
@@ -456,7 +459,7 @@
     mode: os.File.Mode,
 ) os.File.OpenError!os.FileHandle {
     switch (builtin.os) {
-        builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => {
+        builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
             const flags = posix.O_LARGEFILE | posix.O_RDWR | posix.O_CREAT | posix.O_CLOEXEC;
             return await (async openPosix(loop, path, flags, mode) catch unreachable);
         },
@@ -484,7 +487,7 @@
     os_data: OsData,
 
     const OsData = switch (builtin.os) {
-        builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => OsDataPosix,
+        builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => OsDataPosix,
 
         builtin.Os.windows => struct {
             handle: ?os.FileHandle,
@@ -503,7 +506,7 @@
         self.* = CloseOperation{
             .loop = loop,
             .os_data = switch (builtin.os) {
-                builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => initOsDataPosix(self),
+                builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => initOsDataPosix(self),
                 builtin.Os.windows => OsData{ .handle = null },
                 else => @compileError("Unsupported OS"),
             },
@@ -534,6 +537,7 @@
             builtin.Os.macosx,
             builtin.Os.freebsd,
             builtin.Os.netbsd,
+            builtin.Os.dragonfly,
             => {
                 if (self.os_data.have_fd) {
                     self.loop.posixFsRequest(&self.os_data.close_req_node);
@@ -557,6 +561,7 @@
             builtin.Os.macosx,
             builtin.Os.freebsd,
             builtin.Os.netbsd,
+            builtin.Os.dragonfly,
             => {
                 self.os_data.close_req_node.data.msg.Close.fd = handle;
                 self.os_data.have_fd = true;
@@ -575,6 +580,7 @@
             builtin.Os.macosx,
             builtin.Os.freebsd,
             builtin.Os.netbsd,
+            builtin.Os.dragonfly,
             => {
                 self.os_data.have_fd = false;
             },
@@ -591,6 +597,7 @@
             builtin.Os.macosx,
             builtin.Os.freebsd,
             builtin.Os.netbsd,
+            builtin.Os.dragonfly,
             => {
                 assert(self.os_data.have_fd);
                 return self.os_data.close_req_node.data.msg.Close.fd;
@@ -616,6 +623,7 @@
         builtin.Os.macosx,
         builtin.Os.freebsd,
         builtin.Os.netbsd,
+        builtin.Os.dragonfly,
         => return await (async writeFileModeThread(loop, path, contents, mode) catch unreachable),
         builtin.Os.windows => return await (async writeFileWindows(loop, path, contents) catch unreachable),
         else => @compileError("Unsupported OS"),
@@ -721,7 +729,7 @@
         os_data: OsData,
 
         const OsData = switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => struct {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => struct {
                 file_table: FileTable,
                 table_lock: event.Lock,
 
@@ -810,7 +818,7 @@
                     return self;
                 },
 
-                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                     const self = try loop.allocator.create(Self);
                     errdefer loop.allocator.destroy(self);
 
@@ -830,7 +838,7 @@
         /// All addFile calls and removeFile calls must have completed.
         pub fn destroy(self: *Self) void {
             switch (builtin.os) {
-                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                     // TODO we need to cancel the coroutines before destroying the lock
                     self.os_data.table_lock.deinit();
                     var it = self.os_data.file_table.iterator();
@@ -872,7 +880,7 @@
 
         pub async fn addFile(self: *Self, file_path: []const u8, value: V) !?V {
             switch (builtin.os) {
-                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => return await (async addFileKEvent(self, file_path, value) catch unreachable),
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => return await (async addFileKEvent(self, file_path, value) catch unreachable),
                 builtin.Os.linux => return await (async addFileLinux(self, file_path, value) catch unreachable),
                 builtin.Os.windows => return await (async addFileWindows(self, file_path, value) catch unreachable),
                 else => @compileError("Unsupported OS"),
