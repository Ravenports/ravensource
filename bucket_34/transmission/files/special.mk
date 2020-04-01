.if "${VARIANT}" == "web"
do-build:
	@echo "Skipping build of the Transmission web interface."

do-install:
	# do nothing
.endif
