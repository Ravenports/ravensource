# handle dependency on lzo
#
# Feature:	lzo
# Usage:	USES=lzo or USES=lzo:ARGS
# Valid ARGS:	buildrun (default, implicit), build
#

.if !defined(_INCLUDE_USES_LZO_MK)
_INCLUDE_USES_LZO_MK=	yes

# -----------------------------------------------
# Incorporated in ravenadm
# -----------------------------------------------
#.if {lzo_ARGS:Mbuild}
# BUILD_DEPENDS+=	lzo:dev:std
#.else
# BUILD_DEPENDS+=	lzo:dev:std
# BUILDRUN_DEPENDS+=	lzo:primary:std
#.endif
# -----------------------------------------------

.endif
