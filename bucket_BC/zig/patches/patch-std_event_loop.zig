--- std/event/loop.zig.orig	2019-04-08 19:41:41 UTC
+++ std/event/loop.zig
@@ -50,7 +50,7 @@ pub const Loop = struct {
         };
 
         pub const EventFd = switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => KEventFd,
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => KEventFd,
             builtin.Os.linux => struct {
                 base: ResumeNode,
                 epoll_op: u32,
@@ -69,7 +69,7 @@ pub const Loop = struct {
         };
 
         pub const Basic = switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => KEventBasic,
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => KEventBasic,
             builtin.Os.linux => struct {
                 base: ResumeNode,
             },
@@ -221,7 +221,7 @@ pub const Loop = struct {
                     self.extra_threads[extra_thread_index] = try os.spawnThread(self, workerRun);
                 }
             },
-            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                 self.os_data.kqfd = try os.bsdKQueue();
                 errdefer os.close(self.os_data.kqfd);
 
@@ -386,7 +386,7 @@ pub const Loop = struct {
                 os.close(self.os_data.epollfd);
                 self.allocator.free(self.eventfd_resume_nodes);
             },
-            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                 os.close(self.os_data.kqfd);
                 os.close(self.os_data.fs_kqfd);
             },
@@ -501,7 +501,7 @@ pub const Loop = struct {
             const eventfd_node = &resume_stack_node.data;
             eventfd_node.base.handle = next_tick_node.data;
             switch (builtin.os) {
-                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                     const kevent_array = (*const [1]posix.Kevent)(&eventfd_node.kevent);
                     const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
                     _ = os.bsdKEvent(self.os_data.kqfd, kevent_array, empty_kevs, null) catch {
@@ -565,6 +565,7 @@ pub const Loop = struct {
             builtin.Os.macosx,
             builtin.Os.freebsd,
             builtin.Os.netbsd,
+            builtin.Os.dragonfly,
             => self.os_data.fs_thread.wait(),
             else => {},
         }
@@ -629,7 +630,7 @@ pub const Loop = struct {
                     os.posixWrite(self.os_data.final_eventfd, wakeup_bytes) catch unreachable;
                     return;
                 },
-                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                     self.posixFsRequest(&self.os_data.fs_end_request);
                     const final_kevent = (*const [1]posix.Kevent)(&self.os_data.final_kevent);
                     const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
@@ -687,7 +688,7 @@ pub const Loop = struct {
                         }
                     }
                 },
-                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                     var eventlist: [1]posix.Kevent = undefined;
                     const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
                     const count = os.bsdKEvent(self.os_data.kqfd, empty_kevs, eventlist[0..], null) catch unreachable;
@@ -750,7 +751,7 @@ pub const Loop = struct {
         self.beginOneEvent(); // finished in posixFsRun after processing the msg
         self.os_data.fs_queue.put(request_node);
         switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                 const fs_kevs = (*const [1]posix.Kevent)(&self.os_data.fs_kevent_wake);
                 const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
                 _ = os.bsdKEvent(self.os_data.fs_kqfd, fs_kevs, empty_kevs, null) catch unreachable;
@@ -820,7 +821,7 @@ pub const Loop = struct {
                         else => unreachable,
                     }
                 },
-                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
                     const fs_kevs = (*const [1]posix.Kevent)(&self.os_data.fs_kevent_wait);
                     var out_kevs: [1]posix.Kevent = undefined;
                     _ = os.bsdKEvent(self.os_data.fs_kqfd, fs_kevs, out_kevs[0..], null) catch unreachable;
@@ -832,7 +833,7 @@ pub const Loop = struct {
 
     const OsData = switch (builtin.os) {
         builtin.Os.linux => LinuxOsData,
-        builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => KEventData,
+        builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => KEventData,
         builtin.Os.windows => struct {
             io_port: windows.HANDLE,
             extra_thread_count: usize,
