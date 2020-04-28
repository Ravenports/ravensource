#!/bin/sh
#
# $1: prefix
# $2: opsys
# $3: arch
# $4: standardized arch
# $5: OS kernel version
# $6: OS release
# $7: OS Major version
#
# Returns 0 if all the arguments match the installed bmake

bmake=$1/bin/bmake
answer1=$($bmake -V .MAKE.OS.NAME)
answer2=$($bmake -V .MAKE.OS.ARCHITECTURE)
answer3=$($bmake -V .MAKE.OS.ARCH.STANDARD)
answer4=$($bmake -V .MAKE.OS.VERSION)
answer5=$($bmake -V .MAKE.OS.RELEASE)
answer6=$($bmake -V .MAKE.OS.MAJOR)
all="$answer1/$answer2/$answer3/$answer4/$answer5/$answer6"
errmsg="bmake verification test failed, contains $all"
recmsg="Rebuild bmake package and retry.";

if [ "$2" != "$answer1" ]; then
	echo "$errmsg (.MAKE.OS.NAME)"
	echo $recmsg
	exit 1
fi
if [ "$3" != "$answer2" ]; then
	echo "$errmsg (.MAKE.OS.ARCHITECTURE)"
	echo $recmsg
	exit 1
fi
if [ "$4" != "$answer3" ]; then
	echo "$errmsg (.MAKE.OS.ARCH.STANDARD)"
	echo $recmsg
	exit 1
fi
if [ "$5" != "$answer4" ]; then
	echo "$errmsg (.MAKE.OS.VERSION)"
	echo $recmsg
	exit 1
fi
if [ "$6" != "$answer5" ]; then
	echo "$errmsg (.MAKE.OS.RELEASE)"
	echo $recmsg
	exit 1
fi
if [ "$7" != "$answer6" ]; then
	echo "$errmsg (.MAKE.OS.MAJOR)"
	echo $recmsg
	exit 1
fi

echo "bmake verification test passed"
