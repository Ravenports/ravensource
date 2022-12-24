# Strip -ldl from all platforms except linux

.if "${OPSYS}" == "Linux"
SEDINSTR=
.else
SEDINSTR=; s|-ldl||g
.endif
