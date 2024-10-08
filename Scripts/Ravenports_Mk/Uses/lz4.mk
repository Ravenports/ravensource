# handle dependency on lz4
#
# Feature:	lz4
# Usage:	USES=lz4 or USES=lz4:ARGS
# Valid ARGS:	buildrun (default, implicit), build
#

.if !defined(_INCLUDE_USES_LZ4_MK)
_INCLUDE_USES_LZ4_MK=	yes

# -----------------------------------------------
# Incorporated in ravenadm
# -----------------------------------------------
#.if {lz4_ARGS:Mbuild}
# BUILD_DEPENDS+=	lz4:dev:std
#.else
# BUILD_DEPENDS+=	lz4:dev:std
# BUILDRUN_DEPENDS+=	lz4:primary:std
#.endif
# -----------------------------------------------

.endif
