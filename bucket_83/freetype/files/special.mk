SELECTED_MODE=	\
	r=0; \
	for m in ${SUBPIXEL_HINTING_MODE}; \
		do r=$$(($$r | $$m)); \
	done; \
	${ECHO_CMD} $$r
