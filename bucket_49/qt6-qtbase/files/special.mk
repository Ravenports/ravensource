.if empty(FEAT_EVDEV)
PLIST_SUB+=EVDEV-OFF="@comment "
.else
PLIST_SUB+=EVDEV-OFF=
.endif

.if ${OPSYS} == Linux
PLIST_SUB+=FSWTYPE=inotify
PLIST_SUB+=DSSTYPE=udev
.else
PLIST_SUB+=FSWTYPE=kqueue
PLIST_SUB+=DSSTYPE=static
.endif
