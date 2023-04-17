.if empty(FEAT_EVDEV)
PLIST_SUB+=EVDEV-OFF="@comment "
.else
PLIST_SUB+=EVDEV-OFF=
.endif
