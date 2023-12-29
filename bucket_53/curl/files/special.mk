ZQ+=	--with-schannel=no		# enable Windows native SSL/TLS
ZQ+=	--with-secure-transport=no	# enable Apple OS native SSL/TLS
ZQ+=	--with-amissl=no		# enable Amiga native SSL/TLS (AmiSSL)
ZQ+=	--with-gnutls=no		# where to look for GnuTLS
ZQ+=	--with-wolfssl=no		# where to look for WolfSSL
ZQ+=	--with-bearssl=no		# where to look for BearSSL
ZQ+=	--with-rustls=no		# where to look for rustls
ZQ+=	--with-test-caddy=no		# where to find caddy for testing
ZQ+=	--with-hyper=no			# Enable hyper usage
ZQ+=	--with-zlib=${LOCALBASE}	# Enable use of zlib
ZQ+=	--with-brotli=no		# Enable use of BROTLI
ZQ+=	--with-zstd=no			# Enable use of zstd
ZQ+=	--with-libpsl=no		# Support for libpsl cookie checking
ZQ+=	--with-libgsasl=no		# libgsasl support for SCRAM
ZQ+=	--with-libssh=no		# Enable libssh
ZQ+=	--with-wolfssh=no		# Enable wolfssh
ZQ+=	--with-librtmp=no		# Enable librtmp
ZQ+=	--with-winidn=no		# Enable Windows native IDN
ZQ+=	--with-libidn2=no		# Enable libidn2 usage
ZQ+=	--with-ngtcp2=no		# Enable ngtcp2 usage
ZQ+=	--with-nghttp3=no		# Enable nghttp3 usage
ZQ+=	--with-quiche=no		# Enable quiche usage
ZQ+=	--with-msh3=no			# Enable msh3 usage
ZQ+=	--enable-http=yes		# Enable HTTP support
ZQ+=	--enable-file=yes		# Enable FILE support
ZQ+=	--enable-ldap=no		# Enable LDAP support
ZQ+=	--enable-ldaps=no		# Enable LDAPS support
ZQ+=	--enable-libgcc=no		# Use libgcc when linking
ZQ+=	--enable-proxy=yes		# Enable proxy support
ZQ+=	--enable-ipv6=yes		# Enable IPv6 (with IPv4) support
ZQ+=	--enable-pthreads		# Enable POSIX threads (default for threaded resolver)
ZQ+=	--enable-verbose		# Enable verbose strings
ZQ+=	--enable-versioned-symbols=no	# Enable versioned symbols in shared library
ZQ+=	--enable-dnsshuffle=no		# Enable DNS shuffling
ZQ+=	--enable-sspi=no		# Enable SSPI (Windows native builds only)
ZQ+=	--enable-http-auth		# Enable HTTP authentication support
ZQ+=	--enable-basic-auth		# Enable basic authentication
ZQ+=	--enable-unix-sockets		# Enable Unix domain sockets
ZQ+=	--enable-socketpair		# Enable socketpair support
ZQ+=	--enable-bindlocal		# Enable local binding support
ZQ+=	--enable-netrc			# Enable netrc parsing
ZQ+=	--enable-progress-meter		# Enable progress-meter
ZQ+=	--enable-get-easy-options	# Enable curl_easy_options
ZQ+=	--enable-alt-svc		# Enable alt-svc support
ZQ+=	--enable-mime=yes		# Enable mime API support
ZQ+=	--enable-headers-api		# Enable headers-api support
ZQ+=	--enable-websockets=no		# Enable WebSockets support

ZQ+=	--with-zsh-functions-dir=${LOCALBASE}/share/zsh/site-functions
ZQ+=	--with-fish-functions-dir=${LOCALBASE}/share/fish/completions


.if "${VARIANT}" == "embed"
ZQ+=	--with-test-nghttpx=no		# where to find nghttpx for testing
ZQ+=	--with-nghttp2=no		# Enable nghttp2 usage
ZQ+=	--with-libssh2			# Enable libssh2
ZQ+=	--enable-ftp=no			# Enable FTP support
ZQ+=	--enable-rtsp=no		# Enable RTSP support
ZQ+=	--enable-dict=no		# Enable DICT support
ZQ+=	--enable-telnet=no		# Enable TELNET support
ZQ+=	--enable-tftp=no		# Enable TFTP support
ZQ+=	--enable-pop3=no		# Enable POP3 support
ZQ+=	--enable-imap=no		# Enable IMAP support
ZQ+=	--enable-smb=no			# Enable SMB/CIFS support
ZQ+=	--enable-smtp=no		# Enable SMTP support
ZQ+=	--enable-gopher=no		# Enable Gopher support
ZQ+=	--enable-mqtt=no		# Enable MQTT support
ZQ+=	--enable-manual=no		# Enable built-in manual
ZQ+=	--enable-libcurl-option=no	# Enable --libcurl C code generation support
ZQ+=	--enable-bearer-auth=no		# Enable bearer authentication
ZQ+=	--enable-digest-auth=no		# Enable digest authentication
ZQ+=	--enable-kerberos-auth=no	# Enable kerberos authentication
ZQ+=	--enable-negotiate-auth=no	# Enable negotiate authentication
ZQ+=	--enable-aws=no			# Enable AWS sig support
ZQ+=	--enable-ntlm=no		# Enable NTLM support
ZQ+=	--enable-tls-srp=no		# Enable TLS-SRP authentication
ZQ+=	--enable-cookies=no		# Enable cookies support
ZQ+=	--enable-doh=no			# Enable DoH support
ZQ+=	--enable-form-api=no		# Enable form API support
ZQ+=	--enable-dateparse=no		# Enable date parsing
ZQ+=	--enable-hsts=no		# Enable HSTS support

.else

ZQ+=	--with-test-nghttpx=nghttpx
ZQ+=	--with-nghttp2
ZQ+=	--with-libssh2=no
ZQ+=	--enable-ftp=yes
ZQ+=	--enable-rtsp=yes
ZQ+=	--enable-dict=yes
ZQ+=	--enable-telnet=yes
ZQ+=	--enable-tftp=yes
ZQ+=	--enable-pop3=yes
ZQ+=	--enable-imap=yes
ZQ+=	--enable-smb=yes
ZQ+=	--enable-smtp=yes
ZQ+=	--enable-gopher=yes
ZQ+=	--enable-mqtt=yes
ZQ+=	--enable-manual=yes
ZQ+=	--enable-libcurl-option=yes
ZQ+=	--enable-bearer-auth=yes
ZQ+=	--enable-digest-auth=yes
ZQ+=	--enable-kerberos-auth=yes
ZQ+=	--enable-negotiate-auth=yes
ZQ+=	--enable-aws=yes
ZQ+=	--enable-ntlm=yes
ZQ+=	--enable-tls-srp=yes
ZQ+=	--enable-cookies=yes
ZQ+=	--enable-doh=yes
ZQ+=	--enable-form-api=yes
ZQ+=	--enable-dateparse=yes
ZQ+=	--enable-hsts=yes

.endif

CONFIGURE_ARGS+=	${ZQ}
 