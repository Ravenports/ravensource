PREPFILES= \
	builtins.adb \
	parser_bdb.adb \
	parser_btree_io.adb \
	parser_db.adb \
	parser_dbm.adb \
	parser_gnat_cgi.adb \
	parser_hash_io.adb \
	parser_mysql.adb \
	parser_mysqlm.adb \
	parser_pen.adb \
	parser_sound.adb \
	parser_strings_pcre.adb \
	scanner_res.adb \
	scanner_res.ads \
	user_io-getline.adb \
	world.ads

.if ${SETMYSQL} == "ON" || ${SETPGSQL} == "ON"
SFARG+=		-DAPQ=true
SETAPQ=		ON
.else
SFARG+=		-DAPQ=false
.endif

BUILDDATE!=	date "+%y%m%d"
SFARG+=		-DREADLINE=true
SFARG+=		-DBDB=true
SFARG+=		-DconfigbuildDate=\"${BUILDDATE}\"
SFARG+=		-Dconfigreleased=true

# Currently Ada is only available for x86, so we can assume the following
SF_ARCH=		${ARCH_STANDARD:S/x86_64/athlon64/}
SF_CPU_FLAG=		-march
