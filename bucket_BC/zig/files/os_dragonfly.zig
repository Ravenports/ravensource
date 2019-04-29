const builtin = @import("builtin");

pub use @import("dragonfly/errno.zig");

const std = @import("../std.zig");
const c = std.c;

const assert = std.debug.assert;
const maxInt = std.math.maxInt;
pub const Kevent = c.Kevent;

pub const CTL_KERN = 1;
pub const CTL_DEBUG = 5;

pub const KERN_PROC = 14; // struct: process entries
pub const KERN_PROC_PATHNAME = 12; // path to executable

pub const PATH_MAX = 1024;

pub const STDIN_FILENO = 0;
pub const STDOUT_FILENO = 1;
pub const STDERR_FILENO = 2;

pub const PROT_NONE = 0;
pub const PROT_READ = 1;
pub const PROT_WRITE = 2;
pub const PROT_EXEC = 4;

pub const CLOCK_REALTIME = 0;
pub const CLOCK_VIRTUAL = 1;
pub const CLOCK_PROF = 2;
pub const CLOCK_MONOTONIC = 4;
pub const CLOCK_UPTIME = 5;
pub const CLOCK_UPTIME_PRECISE = 7;
pub const CLOCK_UPTIME_FAST = 8;
pub const CLOCK_REALTIME_PRECISE = 9;
pub const CLOCK_REALTIME_FAST = 10;
pub const CLOCK_MONOTONIC_PRECISE = 11;
pub const CLOCK_MONOTONIC_FAST = 12;
pub const CLOCK_SECOND = 13;
pub const CLOCK_THREAD_CPUTIME_ID = 14;
pub const CLOCK_PROCESS_CPUTIME_ID = 15;

pub const MAP_FAILED = maxInt(usize);
pub const MAP_SHARED = 0x0001;
pub const MAP_PRIVATE = 0x0002;
pub const MAP_FIXED = 0x0010;
pub const MAP_STACK = 0x0400;
pub const MAP_NOSYNC = 0x0800;
pub const MAP_ANON = 0x1000;
pub const MAP_ANONYMOUS = MAP_ANON;
pub const MAP_FILE = 0;
pub const MAP_NORESERVE = 0;

pub const MAP_GUARD = 0x00002000;
pub const MAP_EXCL = 0x00004000;
pub const MAP_NOCORE = 0x00020000;
pub const MAP_PREFAULT_READ = 0x00040000;
pub const MAP_32BIT = 0x00080000;

pub const WNOHANG = 1;
pub const WUNTRACED = 2;
pub const WSTOPPED = WUNTRACED;
pub const WCONTINUED = 4;
pub const WNOWAIT = 8;
pub const WEXITED = 16;
pub const WTRAPPED = 32;

pub const SA_ONSTACK = 0x0001;
pub const SA_RESTART = 0x0002;
pub const SA_RESETHAND = 0x0004;
pub const SA_NOCLDSTOP = 0x0008;
pub const SA_NODEFER = 0x0010;
pub const SA_NOCLDWAIT = 0x0020;
pub const SA_SIGINFO = 0x0040;

pub const SIGHUP = 1;
pub const SIGINT = 2;
pub const SIGQUIT = 3;
pub const SIGILL = 4;
pub const SIGTRAP = 5;
pub const SIGABRT = 6;
pub const SIGIOT = SIGABRT;
pub const SIGEMT = 7;
pub const SIGFPE = 8;
pub const SIGKILL = 9;
pub const SIGBUS = 10;
pub const SIGSEGV = 11;
pub const SIGSYS = 12;
pub const SIGPIPE = 13;
pub const SIGALRM = 14;
pub const SIGTERM = 15;
pub const SIGURG = 16;
pub const SIGSTOP = 17;
pub const SIGTSTP = 18;
pub const SIGCONT = 19;
pub const SIGCHLD = 20;
pub const SIGTTIN = 21;
pub const SIGTTOU = 22;
pub const SIGIO = 23;
pub const SIGXCPU = 24;
pub const SIGXFSZ = 25;
pub const SIGVTALRM = 26;
pub const SIGPROF = 27;
pub const SIGWINCH = 28;
pub const SIGINFO = 29;
pub const SIGUSR1 = 30;
pub const SIGUSR2 = 31;
pub const SIGTHR = 32;
pub const SIGLWP = SIGTHR;
pub const SIGLIBRT = 33;

pub const SIGRTMIN = 65;
pub const SIGRTMAX = 126;

// access function
pub const F_OK = 0; // test for existence of file
pub const X_OK = 1; // test for execute or search permission
pub const W_OK = 2; // test for write permission
pub const R_OK = 4; // test for read permission

pub const O_RDONLY = 0x0000;
pub const O_WRONLY = 0x0001;
pub const O_RDWR = 0x0002;
pub const O_ACCMODE = 0x0003;

pub const O_CREAT = 0x0200;
pub const O_EXCL = 0x0800;
pub const O_NOCTTY = 0x8000;
pub const O_TRUNC = 0x0400;
pub const O_APPEND = 0x0008;
pub const O_NONBLOCK = 0x0004;
pub const O_DSYNC = 0o10000;
pub const O_SYNC = 0x0080;
pub const O_RSYNC = 0o4010000;
pub const O_DIRECTORY = 0o200000;
pub const O_NOFOLLOW = 0x0100;
pub const O_CLOEXEC = 0x00100000;

pub const O_ASYNC = 0x0040;
pub const O_DIRECT = 0x00010000;
pub const O_LARGEFILE = 0;
pub const O_NOATIME = 0o1000000;
pub const O_PATH = 0o10000000;
pub const O_TMPFILE = 0o20200000;
pub const O_NDELAY = O_NONBLOCK;

pub const F_DUPFD = 0;
pub const F_GETFD = 1;
pub const F_SETFD = 2;
pub const F_GETFL = 3;
pub const F_SETFL = 4;

pub const F_SETOWN = 8;
pub const F_GETOWN = 9;
pub const F_SETSIG = 10;
pub const F_GETSIG = 11;

pub const F_GETLK = 5;
pub const F_SETLK = 6;
pub const F_SETLKW = 7;

pub const F_SETOWN_EX = 15;
pub const F_GETOWN_EX = 16;

pub const F_GETOWNER_UIDS = 17;

pub const SEEK_SET = 0;
pub const SEEK_CUR = 1;
pub const SEEK_END = 2;

pub const SIG_BLOCK = 1;
pub const SIG_UNBLOCK = 2;
pub const SIG_SETMASK = 3;

pub const SOCK_STREAM = 1;
pub const SOCK_DGRAM = 2;
pub const SOCK_RAW = 3;
pub const SOCK_RDM = 4;
pub const SOCK_SEQPACKET = 5;

pub const SOCK_CLOEXEC = 0x10000000;
pub const SOCK_NONBLOCK = 0x20000000;

pub const PROTO_ip = 0o000;
pub const PROTO_icmp = 0o001;
pub const PROTO_igmp = 0o002;
pub const PROTO_ggp = 0o003;
pub const PROTO_ipencap = 0o004;
pub const PROTO_st = 0o005;
pub const PROTO_tcp = 0o006;
pub const PROTO_egp = 0o010;
pub const PROTO_pup = 0o014;
pub const PROTO_udp = 0o021;
pub const PROTO_hmp = 0o024;
pub const PROTO_xns_idp = 0o026;
pub const PROTO_rdp = 0o033;
pub const PROTO_iso_tp4 = 0o035;
pub const PROTO_xtp = 0o044;
pub const PROTO_ddp = 0o045;
pub const PROTO_idpr_cmtp = 0o046;
pub const PROTO_ipv6 = 0o051;
pub const PROTO_ipv6_route = 0o053;
pub const PROTO_ipv6_frag = 0o054;
pub const PROTO_idrp = 0o055;
pub const PROTO_rsvp = 0o056;
pub const PROTO_gre = 0o057;
pub const PROTO_esp = 0o062;
pub const PROTO_ah = 0o063;
pub const PROTO_skip = 0o071;
pub const PROTO_ipv6_icmp = 0o072;
pub const PROTO_ipv6_nonxt = 0o073;
pub const PROTO_ipv6_opts = 0o074;
pub const PROTO_rspf = 0o111;
pub const PROTO_vmtp = 0o121;
pub const PROTO_ospf = 0o131;
pub const PROTO_ipip = 0o136;
pub const PROTO_encap = 0o142;
pub const PROTO_pim = 0o147;
pub const PROTO_raw = 0o377;

pub const PF_UNSPEC = 0;
pub const PF_LOCAL = 1;
pub const PF_UNIX = PF_LOCAL;
pub const PF_FILE = PF_LOCAL;
pub const PF_INET = 2;
pub const PF_AX25 = 3;
pub const PF_IPX = 4;
pub const PF_APPLETALK = 5;
pub const PF_NETROM = 6;
pub const PF_BRIDGE = 7;
pub const PF_ATMPVC = 8;
pub const PF_X25 = 9;
pub const PF_INET6 = 10;
pub const PF_ROSE = 11;
pub const PF_DECnet = 12;
pub const PF_NETBEUI = 13;
pub const PF_SECURITY = 14;
pub const PF_KEY = 15;
pub const PF_NETLINK = 16;
pub const PF_ROUTE = PF_NETLINK;
pub const PF_PACKET = 17;
pub const PF_ASH = 18;
pub const PF_ECONET = 19;
pub const PF_ATMSVC = 20;
pub const PF_RDS = 21;
pub const PF_SNA = 22;
pub const PF_IRDA = 23;
pub const PF_PPPOX = 24;
pub const PF_WANPIPE = 25;
pub const PF_LLC = 26;
pub const PF_IB = 27;
pub const PF_MPLS = 28;
pub const PF_CAN = 29;
pub const PF_TIPC = 30;
pub const PF_BLUETOOTH = 31;
pub const PF_IUCV = 32;
pub const PF_RXRPC = 33;
pub const PF_ISDN = 34;
pub const PF_PHONET = 35;
pub const PF_IEEE802154 = 36;
pub const PF_CAIF = 37;
pub const PF_ALG = 38;
pub const PF_NFC = 39;
pub const PF_VSOCK = 40;
pub const PF_MAX = 41;

pub const AF_UNSPEC = PF_UNSPEC;
pub const AF_LOCAL = PF_LOCAL;
pub const AF_UNIX = AF_LOCAL;
pub const AF_FILE = AF_LOCAL;
pub const AF_INET = PF_INET;
pub const AF_AX25 = PF_AX25;
pub const AF_IPX = PF_IPX;
pub const AF_APPLETALK = PF_APPLETALK;
pub const AF_NETROM = PF_NETROM;
pub const AF_BRIDGE = PF_BRIDGE;
pub const AF_ATMPVC = PF_ATMPVC;
pub const AF_X25 = PF_X25;
pub const AF_INET6 = PF_INET6;
pub const AF_ROSE = PF_ROSE;
pub const AF_DECnet = PF_DECnet;
pub const AF_NETBEUI = PF_NETBEUI;
pub const AF_SECURITY = PF_SECURITY;
pub const AF_KEY = PF_KEY;
pub const AF_NETLINK = PF_NETLINK;
pub const AF_ROUTE = PF_ROUTE;
pub const AF_PACKET = PF_PACKET;
pub const AF_ASH = PF_ASH;
pub const AF_ECONET = PF_ECONET;
pub const AF_ATMSVC = PF_ATMSVC;
pub const AF_RDS = PF_RDS;
pub const AF_SNA = PF_SNA;
pub const AF_IRDA = PF_IRDA;
pub const AF_PPPOX = PF_PPPOX;
pub const AF_WANPIPE = PF_WANPIPE;
pub const AF_LLC = PF_LLC;
pub const AF_IB = PF_IB;
pub const AF_MPLS = PF_MPLS;
pub const AF_CAN = PF_CAN;
pub const AF_TIPC = PF_TIPC;
pub const AF_BLUETOOTH = PF_BLUETOOTH;
pub const AF_IUCV = PF_IUCV;
pub const AF_RXRPC = PF_RXRPC;
pub const AF_ISDN = PF_ISDN;
pub const AF_PHONET = PF_PHONET;
pub const AF_IEEE802154 = PF_IEEE802154;
pub const AF_CAIF = PF_CAIF;
pub const AF_ALG = PF_ALG;
pub const AF_NFC = PF_NFC;
pub const AF_VSOCK = PF_VSOCK;
pub const AF_MAX = PF_MAX;

pub const DT_UNKNOWN = 0;
pub const DT_FIFO = 1;
pub const DT_CHR = 2;
pub const DT_DIR = 4;
pub const DT_BLK = 6;
pub const DT_REG = 8;
pub const DT_LNK = 10;
pub const DT_SOCK = 12;
pub const DT_WHT = 14;

/// add event to kq (implies enable)
pub const EV_ADD = 0x0001;

/// delete event from kq
pub const EV_DELETE = 0x0002;

/// enable event
pub const EV_ENABLE = 0x0004;

/// disable event (not reported)
pub const EV_DISABLE = 0x0008;

/// only report one occurrence
pub const EV_ONESHOT = 0x0010;

/// clear event state after reporting
pub const EV_CLEAR = 0x0020;

/// force immediate event output
/// ... with or without EV_ERROR
/// ... use KEVENT_FLAG_ERROR_EVENTS
///     on syscalls supporting flags
pub const EV_RECEIPT = 0x0040;

/// disable event after reporting
pub const EV_DISPATCH = 0x0080;

pub const EVFILT_READ = -1;
pub const EVFILT_WRITE = -2;

/// attached to aio requests
pub const EVFILT_AIO = -3;

/// attached to vnodes
pub const EVFILT_VNODE = -4;

/// attached to struct proc
pub const EVFILT_PROC = -5;

/// attached to struct proc
pub const EVFILT_SIGNAL = -6;

/// timers
pub const EVFILT_TIMER = -7;

/// Process descriptors
pub const EVFILT_PROCDESC = -8;

/// Filesystem events
pub const EVFILT_FS = -9;

pub const EVFILT_LIO = -10;

/// User events
pub const EVFILT_USER = -11;

/// Sendfile events
pub const EVFILT_SENDFILE = -12;

pub const EVFILT_EMPTY = -13;

/// On input, NOTE_TRIGGER causes the event to be triggered for output.
pub const NOTE_TRIGGER = 0x01000000;

/// ignore input fflags
pub const NOTE_FFNOP = 0x00000000;

/// and fflags
pub const NOTE_FFAND = 0x40000000;

/// or fflags
pub const NOTE_FFOR = 0x80000000;

/// copy fflags
pub const NOTE_FFCOPY = 0xc0000000;

/// mask for operations
pub const NOTE_FFCTRLMASK = 0xc0000000;
pub const NOTE_FFLAGSMASK = 0x00ffffff;

/// low water mark
pub const NOTE_LOWAT = 0x00000001;

/// behave like poll()
pub const NOTE_FILE_POLL = 0x00000002;

/// vnode was removed
pub const NOTE_DELETE = 0x00000001;

/// data contents changed
pub const NOTE_WRITE = 0x00000002;

/// size increased
pub const NOTE_EXTEND = 0x00000004;

/// attributes changed
pub const NOTE_ATTRIB = 0x00000008;

/// link count changed
pub const NOTE_LINK = 0x00000010;

/// vnode was renamed
pub const NOTE_RENAME = 0x00000020;

/// vnode access was revoked
pub const NOTE_REVOKE = 0x00000040;

/// vnode was opened
pub const NOTE_OPEN = 0x00000080;

/// file closed, fd did not allow write
pub const NOTE_CLOSE = 0x00000100;

/// file closed, fd did allow write
pub const NOTE_CLOSE_WRITE = 0x00000200;

/// file was read
pub const NOTE_READ = 0x00000400;

/// process exited
pub const NOTE_EXIT = 0x80000000;

/// process forked
pub const NOTE_FORK = 0x40000000;

/// process exec'd
pub const NOTE_EXEC = 0x20000000;

/// mask for signal & exit status
pub const NOTE_PDATAMASK = 0x000fffff;
pub const NOTE_PCTRLMASK = (~NOTE_PDATAMASK);

/// data is seconds
pub const NOTE_SECONDS = 0x00000001;

/// data is milliseconds
pub const NOTE_MSECONDS = 0x00000002;

/// data is microseconds
pub const NOTE_USECONDS = 0x00000004;

/// data is nanoseconds
pub const NOTE_NSECONDS = 0x00000008;

/// timeout is absolute
pub const NOTE_ABSTIME = 0x00000010;

pub const TCGETS = 0x5401;
pub const TCSETS = 0x5402;
pub const TCSETSW = 0x5403;
pub const TCSETSF = 0x5404;
pub const TCGETA = 0x5405;
pub const TCSETA = 0x5406;
pub const TCSETAW = 0x5407;
pub const TCSETAF = 0x5408;
pub const TCSBRK = 0x5409;
pub const TCXONC = 0x540A;
pub const TCFLSH = 0x540B;
pub const TIOCEXCL = 0x540C;
pub const TIOCNXCL = 0x540D;
pub const TIOCSCTTY = 0x540E;
pub const TIOCGPGRP = 0x540F;
pub const TIOCSPGRP = 0x5410;
pub const TIOCOUTQ = 0x5411;
pub const TIOCSTI = 0x5412;
pub const TIOCGWINSZ = 0x5413;
pub const TIOCSWINSZ = 0x5414;
pub const TIOCMGET = 0x5415;
pub const TIOCMBIS = 0x5416;
pub const TIOCMBIC = 0x5417;
pub const TIOCMSET = 0x5418;
pub const TIOCGSOFTCAR = 0x5419;
pub const TIOCSSOFTCAR = 0x541A;
pub const FIONREAD = 0x541B;
pub const TIOCINQ = FIONREAD;
pub const TIOCLINUX = 0x541C;
pub const TIOCCONS = 0x541D;
pub const TIOCGSERIAL = 0x541E;
pub const TIOCSSERIAL = 0x541F;
pub const TIOCPKT = 0x5420;
pub const FIONBIO = 0x5421;
pub const TIOCNOTTY = 0x5422;
pub const TIOCSETD = 0x5423;
pub const TIOCGETD = 0x5424;
pub const TCSBRKP = 0x5425;
pub const TIOCSBRK = 0x5427;
pub const TIOCCBRK = 0x5428;
pub const TIOCGSID = 0x5429;
pub const TIOCGRS485 = 0x542E;
pub const TIOCSRS485 = 0x542F;
pub const TIOCGPTN = 0x80045430;
pub const TIOCSPTLCK = 0x40045431;
pub const TIOCGDEV = 0x80045432;
pub const TCGETX = 0x5432;
pub const TCSETX = 0x5433;
pub const TCSETXF = 0x5434;
pub const TCSETXW = 0x5435;
pub const TIOCSIG = 0x40045436;
pub const TIOCVHANGUP = 0x5437;
pub const TIOCGPKT = 0x80045438;
pub const TIOCGPTLCK = 0x80045439;
pub const TIOCGEXCL = 0x80045440;

pub const sockaddr = c.sockaddr;
pub const sockaddr_in = c.sockaddr_in;
pub const sockaddr_in6 = c.sockaddr_in6;

fn unsigned(s: i32) u32 {
    return @bitCast(u32, s);
}
fn signed(s: u32) i32 {
    return @bitCast(i32, s);
}
pub fn WEXITSTATUS(s: i32) i32 {
    return signed((unsigned(s) & 0xff00) >> 8);
}
pub fn WTERMSIG(s: i32) i32 {
    return signed(unsigned(s) & 0x7f);
}
pub fn WSTOPSIG(s: i32) i32 {
    return WEXITSTATUS(s);
}
pub fn WIFEXITED(s: i32) bool {
    return WTERMSIG(s) == 0;
}
pub fn WIFSTOPPED(s: i32) bool {
    return @intCast(u16, (((unsigned(s) & 0xffff) *% 0x10001) >> 8)) > 0x7f00;
}
pub fn WIFSIGNALED(s: i32) bool {
    return (unsigned(s) & 0xffff) -% 1 < 0xff;
}

pub const winsize = extern struct {
    ws_row: u16,
    ws_col: u16,
    ws_xpixel: u16,
    ws_ypixel: u16,
};

/// Get the errno from a syscall return value, or 0 for no error.
pub fn getErrno(r: usize) usize {
    const signed_r = @bitCast(isize, r);
    return if (signed_r > -4096 and signed_r < 0) @intCast(usize, -signed_r) else 0;
}

pub fn dup2(old: i32, new: i32) usize {
    return errnoWrap(c.dup2(old, new));
}

pub fn chdir(path: [*]const u8) usize {
    return errnoWrap(c.chdir(path));
}

pub fn execve(path: [*]const u8, argv: [*]const ?[*]const u8, envp: [*]const ?[*]const u8) usize {
    return errnoWrap(c.execve(path, argv, envp));
}

pub fn fork() usize {
    return errnoWrap(c.fork());
}

pub fn access(path: [*]const u8, mode: u32) usize {
    return errnoWrap(c.access(path, mode));
}

pub fn getcwd(buf: [*]u8, size: usize) usize {
    return if (c.getcwd(buf, size) == null) @bitCast(usize, -isize(c._errno().*)) else 0;
}

pub fn getdents(fd: i32, dirp: [*]u8, count: usize) usize {
    return errnoWrap(@bitCast(isize, c.getdents(fd, drip, count)));
}

pub fn getdirentries(fd: i32, buf_ptr: [*]u8, buf_len: usize, basep: *i64) usize {
    return errnoWrap(@bitCast(isize, c.getdirentries(fd, buf_ptr, buf_len, basep)));
}

pub fn realpath(noalias filename: [*]const u8, noalias resolved_name: [*]u8) usize {
    return if (c.realpath(filename, resolved_name) == null) @bitCast(usize, -isize(c._errno().*)) else 0;
}

pub fn isatty(fd: i32) bool {
    return c.isatty(fd) != 0;
}

pub fn readlink(noalias path: [*]const u8, noalias buf_ptr: [*]u8, buf_len: usize) usize {
    return errnoWrap(c.readlink(path, buf_ptr, buf_len));
}

pub fn mkdir(path: [*]const u8, mode: u32) usize {
    return errnoWrap(c.mkdir(path, mode));
}

pub fn mmap(address: ?[*]u8, length: usize, prot: usize, flags: u32, fd: i32, offset: isize) usize {
    const ptr_result = c.mmap(
        @ptrCast(?*c_void, address),
        length,
        @bitCast(c_int, @intCast(c_uint, prot)),
        @bitCast(c_int, c_uint(flags)),
        fd,
        offset,
    );
    const isize_result = @bitCast(isize, @ptrToInt(ptr_result));
    return errnoWrap(isize_result);
}

pub fn munmap(address: usize, length: usize) usize {
    return errnoWrap(c.munmap(@intToPtr(?*c_void, address), length));
}

pub fn read(fd: i32, buf: [*]u8, nbyte: usize) usize {
    return errnoWrap(c.read(fd, @ptrCast(*c_void, buf), nbyte));
}

pub fn rmdir(path: [*]const u8) usize {
    return errnoWrap(c.rmdir(path));
}

pub fn symlink(existing: [*]const u8, new: [*]const u8) usize {
    return errnoWrap(c.symlink(existing, new));
}

pub fn pread(fd: i32, buf: [*]u8, nbyte: usize, offset: u64) usize {
    return errnoWrap(c.pread(fd, @ptrCast(*c_void, buf), nbyte, offset));
}

pub fn preadv(fd: i32, iov: [*]const iovec, count: usize, offset: usize) usize {
    return errnoWrap(c.preadv(fd, @ptrCast(*const c_void, iov), @intCast(c_int, count), offset));
}

pub fn pipe(fd: *[2]i32) usize {
    return pipe2(fd, 0);
}

pub fn pipe2(fd: *[2]i32, flags: u32) usize {
    comptime assert(i32.bit_count == c_int.bit_count);
    return errnoWrap(c.pipe2(@ptrCast(*[2]c_int, fd), flags));
}

pub fn write(fd: i32, buf: [*]const u8, nbyte: usize) usize {
    return errnoWrap(c.write(fd, @ptrCast(*const c_void, buf), nbyte));
}

pub fn pwrite(fd: i32, buf: [*]const u8, nbyte: usize, offset: u64) usize {
    return errnoWrap(c.pwrite(fd, @ptrCast(*const c_void, buf), nbyte, offset));
}

pub fn pwritev(fd: i32, iov: [*]const iovec_const, count: usize, offset: usize) usize {
    return errnoWrap(c.pwritev(fd, @ptrCast(*const c_void, iov), @intCast(c_int, count), offset));
}

pub fn rename(old: [*]const u8, new: [*]const u8) usize {
    return errnoWrap(c.rename(old, new));
}

pub fn open(path: [*]const u8, flags: u32, mode: usize) usize {
    return errnoWrap(c.open(path, @bitCast(c_int, flags), mode));
}

pub fn create(path: [*]const u8, perm: usize) usize {
    return arch.syscall2(SYS_creat, @ptrToInt(path), perm);
}

pub fn openat(dirfd: i32, path: [*]const u8, flags: usize, mode: usize) usize {
    return errnoWrap(c.openat(@bitCast(usize, isize(dirfd)), @ptrToInt(path), flags, mode));
}

pub fn close(fd: i32) usize {
    return errnoWrap(c.close(fd));
}

pub fn lseek(fd: i32, offset: isize, whence: c_int) usize {
    return errnoWrap(c.lseek(fd, offset, whence));
}

pub fn exit(code: i32) noreturn {
    c.exit(code);
}

pub fn kill(pid: i32, sig: i32) usize {
    return errnoWrap(c.kill(pid, sig));
}

pub fn unlink(path: [*]const u8) usize {
    return errnoWrap(c.unlink(path));
}

pub fn waitpid(pid: i32, status: *i32, options: u32) usize {
    comptime assert(i32.bit_count == c_int.bit_count);
    return errnoWrap(c.waitpid(pid, @ptrCast(*c_int, status), @bitCast(c_int, options)));
}

pub fn nanosleep(req: *const timespec, rem: ?*timespec) usize {
    return errnoWrap(c.nanosleep(req, rem));
}

pub fn clock_gettime(clk_id: i32, tp: *timespec) usize {
    return errnoWrap(c.clock_gettime(clk_id, tp));
}

pub fn clock_getres(clk_id: i32, tp: *timespec) usize {
    return errnoWrap(c.clock_getres(clk_id, tp));
}

pub fn setuid(uid: u32) usize {
    return errnoWrap(c.setuid(uid));
}

pub fn setgid(gid: u32) usize {
    return errnoWrap(c.setgid(gid));
}

pub fn setreuid(ruid: u32, euid: u32) usize {
    return errnoWrap(c.setreuid(ruid, euid));
}

pub fn setregid(rgid: u32, egid: u32) usize {
    return errnoWrap(c.setregid(rgid, egid));
}

const NSIG = 32;

pub const SIG_ERR = @intToPtr(extern fn (i32) void, maxInt(usize));
pub const SIG_DFL = @intToPtr(extern fn (i32) void, 0);
pub const SIG_IGN = @intToPtr(extern fn (i32) void, 1);

/// Renamed from `sigaction` to `Sigaction` to avoid conflict with the syscall.
pub const Sigaction = extern struct {
    /// signal handler
    __sigaction_u: extern union {
        __sa_handler: extern fn (i32) void,
        __sa_sigaction: extern fn (i32, *__siginfo, usize) void,
    },

    /// see signal options
    sa_flags: u32,

    /// signal mask to apply
    sa_mask: sigset_t,
};

pub const _SIG_WORDS = 4;
pub const _SIG_MAXSIG = 128;

pub inline fn _SIG_IDX(sig: usize) usize {
    return sig - 1;
}
pub inline fn _SIG_WORD(sig: usize) usize {
    return_SIG_IDX(sig) >> 5;
}
pub inline fn _SIG_BIT(sig: usize) usize {
    return 1 << (_SIG_IDX(sig) & 31);
}
pub inline fn _SIG_VALID(sig: usize) usize {
    return sig <= _SIG_MAXSIG and sig > 0;
}

pub const sigset_t = extern struct {
    __bits: [_SIG_WORDS]u32,
};

pub fn raise(sig: i32) usize {
    return errnoWrap(c.raise(sig));
}

pub const Stat = c.Stat;
pub const dirent = c.dirent;
pub const timespec = c.timespec;

pub fn fstat(fd: i32, buf: *c.Stat) usize {
    return errnoWrap(c.fstat(fd, buf));
}
pub const iovec = extern struct {
    iov_base: [*]u8,
    iov_len: usize,
};

pub const iovec_const = extern struct {
    iov_base: [*]const u8,
    iov_len: usize,
};

// TODO avoid libc dependency
pub fn kqueue() usize {
    return errnoWrap(c.kqueue());
}

// TODO avoid libc dependency
pub fn kevent(kq: i32, changelist: []const Kevent, eventlist: []Kevent, timeout: ?*const timespec) usize {
    return errnoWrap(c.kevent(
        kq,
        changelist.ptr,
        @intCast(c_int, changelist.len),
        eventlist.ptr,
        @intCast(c_int, eventlist.len),
        timeout,
    ));
}

// TODO avoid libc dependency
pub fn sysctl(name: [*]c_int, namelen: c_uint, oldp: ?*c_void, oldlenp: ?*usize, newp: ?*c_void, newlen: usize) usize {
    return errnoWrap(c.sysctl(name, namelen, oldp, oldlenp, newp, newlen));
}

// TODO avoid libc dependency
pub fn sysctlbyname(name: [*]const u8, oldp: ?*c_void, oldlenp: ?*usize, newp: ?*c_void, newlen: usize) usize {
    return errnoWrap(c.sysctlbyname(name, oldp, oldlenp, newp, newlen));
}

// TODO avoid libc dependency
pub fn sysctlnametomib(name: [*]const u8, mibp: ?*c_int, sizep: ?*usize) usize {
    return errnoWrap(c.sysctlnametomib(name, wibp, sizep));
}

// TODO avoid libc dependency

/// Takes the return value from a syscall and formats it back in the way
/// that the kernel represents it to libc. Errno was a mistake, let's make
/// it go away forever.
fn errnoWrap(value: isize) usize {
    return @bitCast(usize, if (value == -1) -isize(c._errno().*) else value);
}
