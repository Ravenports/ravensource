# handle dependency on bzip2
#
# Feature:	bz2
# Usage:	USES=bz2 or USES=bz2:ARGS
# Valid ARGS:	buildrun (default, implicit), build
#

.if !defined(_INCLUDE_USES_BZ2_MK)
_INCLUDE_USES_BZ2_MK=	yes

# -----------------------------------------------
# Incorporated in ravenadm
# -----------------------------------------------
#.if {bz2_ARGS:Mbuild}
# BUILD_DEPENDS+=	bzip2:dev:std
#.else
# BUILD_DEPENDS+=	bzip2:dev:std
# BUILDRUN_DEPENDS+=	bzip2:primary:std
#.endif
# -----------------------------------------------

.endif
