# handle dependency on clang (only affects build dependencies)
#
# Feature:	clang
# Usage:	USES=clang
# Valid ARGS:   keepcc
#

.if !defined(_INCLUDE_USES_CLANG_MK)
_INCLUDE_USES_CLANG_MK=	yes

# -----------------------------------------------------
# Incorporated in ravenadm
# -----------------------------------------------------
# BUILD_DEPENDS+=	clang:complete:std
# -----------------------------------------------------

.if ${clang_ARGS:Mkeepcc}
KEEPCC=	yes
.else
CC=	clang
CXX=	clang++
.endif

.endif
