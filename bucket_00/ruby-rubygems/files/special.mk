.if "${VARIANT}" == "v23"
GEMLINK2.4="@comment "
GEMLINK2.3=""
.endif

.if "${VARIANT}" == "v24"
GEMLINK2.3="@comment "
GEMLINK2.4=""
.endif

PLIST_SUB+= GEMLINK=${GEMLINK${RUBY_DEFAULT}}
