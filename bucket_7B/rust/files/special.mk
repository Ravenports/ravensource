.if "${OPSYS}" == "DragonFly"
DF_INDEX+=		2 3 4
COMPEXT=		zst
.elif "${OPSYS}" == "FreeBSD"
DF_INDEX+=		5 6 7
COMPEXT=		gz
.elif "${OPSYS}" == "Linux"
DF_INDEX+=		8 9 10
COMPEXT=		gz
SFX=			${ARCH_STANDARD}-unknown-linux-gnu
.elif "${OPSYS}" == "NetBSD"
DF_INDEX+=		11 12 13
COMPEXT=		gz
.elif "${OPSYS}" == "SunOS"
DF_INDEX+=		14 15 16
COMPEXT=		gz
SFX=			${ARCH_STANDARD}-unknown-illumos
.elif "${OPSYS}" == "MidnightBSD"
DF_INDEX+=		5 6 7
COMPEXT=		gz
SFX=			${ARCH_STANDARD}-unknown-freebsd
.endif
SFX?=			${ARCH_STANDARD}-unknown-${OPSYS:tl}
SRC_RUSTC?=		rustc-${BOOTSTRAP_RUST}-${SFX}
SRC_RUSTSTD?=		rust-std-${BOOTSTRAP_RUST}-${SFX}
SRC_CARGO?=		cargo-${BOOTSTRAP_CARGO}-${SFX}
