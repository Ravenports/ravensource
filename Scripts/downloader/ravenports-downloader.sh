#!/bin/sh
# The purpose of this script is to install a fully functional
# and fully configured ravensw binary on the machine in order
# to be able to use Ravenports immediately.
# It will select the package set that matches the ABI of the
# install machine.  If that package set does not exist, it
# will set the ABI to the latest package set available.
#
# shellcheck disable=SC3043
# Last-Modified: 17 APR 2023

OPSYS=$(uname -s)
if [ "$OPSYS" = "SunOS" ]; then
   THIS_USER=$(/usr/xpg4/bin/id -un)
else
   THIS_USER=$(id -un)
fi
REPOSITE="http://www.ravenports.com/repository"
ABI_AWK="/tmp/abi.awk"
LOCAL_INV="/tmp/repo-inventory.txt"
LOCAL_ARCHIVE="/tmp/ravensw.gz"

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
			if which curl
			then
				echo "curl ${url} --output ${local_file}"
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
			kernelver=$(uname -K)   #1202000, get first 2 digits
			release=$(echo "$kernelver" | awk '{print substr($0,1,2)}')
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
			# if readelf not present, assume 2.6.32
			if which readelf >/dev/null; then
				linux_abi=$(readelf -n /bin/bash  | awk '/ABI:/ {print $NF}')
			else
				linux_abi="2.6.32"
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
    if (\$2 == "$current_release") {
       print \$4
       printed=1
    }
    last_seen = \$4
  }
}
END {if (!printed) {print last_seen}}
EOF
	awk -f "$ABI_AWK" "$LOCAL_INV"
}

create_tree() {
	mkdir -p "/raven/etc/ravensw/keys"
	mkdir -p "/raven/etc/ravensw/repos"
	mkdir -p "/raven/sbin"

	echo "Created /raven directory hierarchy"
}

create_ravensw_conf() {
	local myabi
	local conf_file
	myabi="$1"
	conf_file="/raven/etc/ravensw.conf"
	echo "ABI = \"${myabi}\"" > "$conf_file"
	echo "Set ravensw ABI to '$myabi' via ravensw.conf"
}

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
	conf_file="/raven/etc/ravensw/repos/01_raven.conf"
	cat << EOF > "$conf_file"
Raven: {
    url            : http://www.ravenports.com/repository/\${ABI},
    pubkey         : /raven/etc/ravensw/keys/ravenports.key,
    signature_type : PUBKEY,
    priority       : 0,
    enabled        : yes
}
EOF
	echo "Installed Remote Ravenports Repository configuration"
}

install_ravensw() {
	local myabi
	local zipped_ravensw
	myabi="$1"
	zipped_ravensw="${REPOSITE}/${myabi}/Latest/ravensw.gz"
	cmd=$(fetch_command "$zipped_ravensw" "$LOCAL_ARCHIVE")
	if ! $cmd; then
		echo "install_ravensw failed to fetch ravensw archive."
		exit 1
	fi
	if ! gunzip "$LOCAL_ARCHIVE"; then
		echo "install_ravensw failed to unzip ravensw archive."
		exit 1
	fi
	mv "/tmp/ravensw" "/raven/sbin/ravensw"
	chmod 755 "/raven/sbin/ravensw"
	echo "Installed ravensw binary at /raven/sbin/"
}

check_for_prereqs() {
	case "$OPSYS" in
		Linux)
			if ! which curl; then
			    if ! which wget; then
				echo "The download requires curl or wget on Linux"
				echo "Neither program was found."
				exit 1
			    fi
			fi
			;;
		*) ;;
	esac
}

check_for_prereqs
get_release
abi=$(get_abi)
create_tree
create_ravensw_conf "$abi"
create_ravenports_key
create_ravenports_repo_conf
install_ravensw "$abi"
clean_up

echo "Ravenports bootstrap is complete."
