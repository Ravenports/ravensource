# handle dependency on clang (only affects build dependencies)
#
# Feature:	clang
# Usage:	USES=clang
#
#

.if !defined(_INCLUDE_USES_CLANG_MK)
_INCLUDE_USES_CLANG_MK=	yes

# -----------------------------------------------------
# Incorporated in ravenadm
# -----------------------------------------------------
# BUILD_DEPENDS+=	clang:complete:standard
# -----------------------------------------------------

CC=	clang
CXX=	clang++

.endif
