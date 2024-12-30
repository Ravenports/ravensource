#!/bin/sh
# The purpose of this script is to install a fully functional and fully
# configured rvn binary on the machine in order to be able to use
# Ravenports immediately.
# It will select the package set that matches the ABI of the install
# machine.  If that package set does not exist, it will set the ABI to
# the latest package set available.
#
# shellcheck disable=SC3043
# Last-Modified: 30 DEC 2024

OPSYS=$(uname -s)
if [ "$OPSYS" = "SunOS" ]; then
   THIS_USER=$(/usr/xpg4/bin/id -un)
else
   THIS_USER=$(id -un)
fi
REPOSITE="http://www.ravenports.com/repository"
ABI_AWK="/tmp/abi.awk"
LOCAL_INV="/tmp/repo-inventory.txt"
LOCAL_ARCHIVE="/tmp/rvn.tgz"
LOCAL_FPRINTDIR="/raven/etc/rvn/fingerprints/ravenports"
LOCAL_REPODIR="/raven/etc/rvn/repos"
LOCAL_CONF="/raven/etc/rvn.conf"

if [ "$THIS_USER" != "root" ]; then
	echo "This script must be executed by the root user."
	exit 0
fi

fetch_command() {
	local url="$1"
	local local_file="$2"

	case "$OPSYS" in
		FreeBSD|MidnightBSD|DragonFly)
			echo "fetch ${url} -o ${local_file}"
			;;
		NetBSD)
			echo "ftp -o ${local_file} ${url}"
			;;
		SunOS)
			echo "/usr/sfw/bin/wget ${url} -O ${local_file}"
			;;
		Darwin)
			echo "curl ${url} --output ${local_file}"
			;;
		Linux)
			if which curl >/dev/null
			then
				echo "curl ${url} --output ${local_file} --silent"
			else
				echo "wget ${url} -O ${local_file}"
			fi
			;;
		*)
			echo "fetch_command: Unrecognized platform"
			exit 1
	esac
}

fetch_inventory() {
	local inventory
	local cmd
	inventory="${REPOSITE}/inventory.txt"
	cmd=$(fetch_command "$inventory" "$LOCAL_INV")
	if ! $cmd; then
		echo "fetch_inventory failed."
		exit 1
	fi
}

get_release() {
	local kernelver
	local relstr
	case "$OPSYS" in
		FreeBSD)
			releaselevel=$(uname -r)   #1202000, get first 2 digits
			release=$(echo "$releaselevel" | awk '{print substr($0,1,2)}')
			echo "$release"
			;;
		DragonFly)
			# odd numbers must round up
			relstr=$(uname -r)      #6.4-RELEASE, 6.5-DEVELOPMENT
			release=$(echo "$relstr" | awk '{split($0,n,"-"); split(n[1],x,"."); Y=(x[2] % 2)? x[2]+1 : x[2]; print x[1] "." Y}')
			echo "$release"
			;;
		MidnightBSD)
			kernelver=$(uname -r)   # 3.0.0, split, take first component
			release=$(echo "$kernelver" | awk '{split($1,r,"."); print r[1]}')
			echo "$release"
			;;
		NetBSD)
			relstr=$(uname -r)      # 9.3, split, take first component
			release=$(echo "$relstr" | awk '{split($1,r,"."); print r[1]}')
			echo "$release"
			;;
		Darwin)
			relstr=$(uname -r)      # 17.7.0, split, take first component
			release=$(echo "$relstr" | awk '{split($1,r,"."); print r[1]}')
			echo "$release"
			;;
		Linux)
			# partial readelf -n output: "    OS: Linux, ABI: 2.6.32"
			# if readelf not present, assume latest ABI (3.2.0)
			if which readelf >/dev/null; then
				linux_abi=$(readelf -n /bin/hostname  | awk '/ABI:/ {print $NF}')
			else
				linux_abi="3.2.0"
				echo "readelf missing, unable to determine ABI"
				echo "defaulting to ${linux_abi}"
				echo "edit /raven/etc/rvn/repos/raven.conf if necessary"
			fi
			echo "$linux_abi"
			;;
		SunOS)
			relstr=$(uname -r)      # 5l.10, split, take second component
			release=$(echo "$relstr" | awk '{split($1,r,"."); print r[2]}')
			echo "$release"
			;;
		*)
			echo "$OPSYS release is not defined yet"
			exit 1
			;;
	esac
}

clean_up() {
	rm -f "$LOCAL_ARCHIVE"
	rm -f "$LOCAL_INV"
	rm -f "$ABI_AWK"
}

get_abi() {
	local current_release
	current_release=$(get_release)
	fetch_inventory
	cat << EOF > "$ABI_AWK"
{
  if (\$1 == "$OPSYS") {
    if (\$5 == "rvn") {
      if (\$2 == "$current_release") {
         print \$4
         printed=1
      }
      last_seen = \$4
    }
  }
}
END {if (!printed) {print last_seen}}
EOF
	awk -f "$ABI_AWK" "$LOCAL_INV"
}

create_tree() {
	mkdir -p "${LOCAL_FPRINTDIR}/trusted"
	mkdir -p "${LOCAL_REPODIR}"
	mkdir -p "/raven/sbin"
	mkdir -p "/raven/share/certs"

	echo "Created /raven directory hierarchy"
}

# currently not used
create_rvn_conf() {
	local myabi
	local conf_file
	myabi="$1"
	conf_file="/raven/etc/rvn.conf"
	echo "ABI: \"${myabi}\"" > "$conf_file"
	echo "Set rvn ABI to '$myabi' via rvn.conf"
}

create_ravenports_fingerprint() {
	local official_version="Alpha"
	local raven_fingerprint="${LOCAL_FPRINTDIR}/trusted/${official_version}-fingerprint"

	cat << EOF > "$raven_fingerprint"
function: "blake3"
fingerprint: "adcb0aeb115a8ca66e4cce5ad1d500ad235cc2eab0a14fdb8bb74f786b896c97"
EOF
	echo "Installed ${official_version} fingerprint file"
}

# currently not used.  equivalent to fingerprint
create_ravenports_key() {
	local key_file
	key_file="/raven/etc/ravensw/keys/ravenports.key"
	cat << EOF > "$key_file"
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4rhIOkp+aJS04AOz/V0S
gKOg7Ol/rUTUeHUwzbE45vvGq+M7s00MKDhzdU6QBPnhRLaPdRf8jJNCcNIEIjQ4
fON43BNJfJX1q5T1jnT4Dd+pyyejPv3gOQdDARYt4risfeey3BBYQMuOghGoCNDt
DYPsWaBUPHUR+Um96U0CYHl3ZeAbovq466Wn3OuYX3gvg4QPaMPKmx1fgI3V9bDA
KuOBD5JEVzhJgtzv33e7C0murs4WWJpRv3eSinZsUKoFbt4F4To+YrIXnOQPrNdr
u25Z5hSBdNT5gM43JKWWqM57Zi60Poj5nG6p+GxGePWrraOQY68mgDEScTrJLIXj
UwIDAQAB
-----END PUBLIC KEY-----
EOF
	echo "Installed Ravenports key"
}

create_ravenports_repo_conf() {
	local conf_file
	conf_file="${LOCAL_REPODIR}/raven.conf"
cat << EOF > "$conf_file"
Raven: {
    url            : http://www.ravenports.com/repository/\${ABI},
    enabled        : true
    master         : true
    signature_type : fingerprints
    fingerprints   : ${LOCAL_FPRINTDIR}
    priority       : 10
}
EOF
	echo "Installed Remote Ravenports Repository configuration"
}

install_rvn() {
	local myabi
	local zipped_rvn
	myabi="$1"
	zipped_rvn="${REPOSITE}/${myabi}/rvn.tgz"
	cmd=$(fetch_command "$zipped_rvn" "$LOCAL_ARCHIVE")
	if ! $cmd; then
		echo "install_rvn failed to fetch rvn archive."
		exit 1
	fi
	if ! tar -C /tmp -xf "$LOCAL_ARCHIVE"; then
		echo "install_rvn failed to unzip rvn archive."
		exit 1
	fi
	rm "$LOCAL_ARCHIVE"
	mv "/tmp/rvn" "/raven/sbin/rvn"
	mv "/tmp/ca-root-nss.crt" "/raven/share/certs/ca-root-nss.crt"
	chmod 755 "/raven/sbin/rvn"
	echo "Installed rvn binary at /raven/sbin"
	echo "Installed NSS CA root certificate at /raven/share/certs"
}

check_for_prereqs() {
	case "$OPSYS" in
		Linux)
			if ! which curl >/dev/null; then
			    if ! which wget >/dev/null; then
				echo "The download requires curl or wget on Linux"
				echo "Neither program was found."
				exit 1
			    fi
			fi
			;;
		*) ;;
	esac
}

fetch_catalog() {
	local myabi
	myabi="$1"
	if ! /raven/sbin/rvn -o "abi=${myabi}" catalog --force
	then
		echo "Failed to fetch the remote catalog"
		exit 1
	fi
}

remove_existing_conf() {
	rm -f "$LOCAL_CONF"
}

install_full_rvn_package() {
	local myabi
	myabi="$1"
	if ! /raven/sbin/rvn -o "abi=${myabi}" install -y rvn~set nss~caroot~std
	then
		echo "Failed to install the full rvn package"
		exit 1
	fi
}

get_calculated_abi() {
	calc=$(/raven/sbin/rvn config abi)
	echo "$calc"
}

override_abi_setting() {
	local downloaded_abi
	local calculated_abi
	downloaded_abi="$1"
	calculated_abi="$2"
	if [ "$downloaded_abi" != "$calculated_abi" ]; then
		sed -e "s|^#ABI:.*|ABI: ${downloaded_abi}|" "${LOCAL_CONF}.sample" > "$LOCAL_CONF"
	fi
}

provide_information() {
	echo
	echo "You can begin installing binary packages directly now."
	echo "To build your own packages, run '/raven/sbin/rvn install ravenports'"
}


check_for_prereqs
abi=$(get_abi)
create_tree
create_ravenports_fingerprint
create_ravenports_repo_conf
install_rvn "$abi"
clean_up
fetch_catalog "$abi"
remove_existing_conf
install_full_rvn_package "$abi"
default_abi=$(get_calculated_abi)
override_abi_setting "$abi" "$default_abi"

echo "Ravenports bootstrap is complete."

provide_information
