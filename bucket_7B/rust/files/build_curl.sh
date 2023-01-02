#!/bin/sh

PREFIX="$1"
CONFIGURE_TARGET="$2"

cd /construction/rust/curl-* || exit
CONFIG_GUESS_DIRS=$(find * -name config.guess -o -name config.sub | xargs -n 1 dirname 2>/dev/null)
for _D in ${CONFIG_GUESS_DIRS}; do \
	rm "${_D}/config.guess"; \
	cp /xports/Mk/Templates/config.guess "${_D}/config.guess"; \
	chmod a+rx "${_D}/config.guess"; \
	rm "${_D}/config.sub"; \
	cp /xports/Mk/Templates/config.sub "${_D}/config.sub"; \
	chmod a+rx "${_D}/config.sub"; \
done

env MAKE=gmake \
	CONFIG_SITE=/xports/Mk/Templates/config.site \
/bin/sh configure \
	--prefix="${PREFIX}" \
	--build="${CONFIGURE_TARGET}" \
	--disable-werror \
	--disable-shared \
	--disable-imap \
	--disable-pop3 \
	--disable-smtp \
	--with-ca-bundle="${PREFIX}/share/certs/ca-root-nss.crt" \
	--enable-cookies \
	--without-nghttp2 \
	--with-ssl="${PREFIX}/libressl" \
	--enable-pthreads \
	--enable-threaded-resolver
