--- src/make.bash.orig	2023-04-01 02:15:36 UTC
+++ src/make.bash
@@ -101,7 +101,7 @@ done
 # Test for debian/kFreeBSD.
 # cmd/dist will detect kFreeBSD as freebsd/$GOARCH, but we need to
 # disable cgo manually.
-if [ "$(uname -s)" == "GNU/kFreeBSD" ]; then
+if [ "$(uname -s)" = "GNU/kFreeBSD" ]; then
         export CGO_ENABLED=0
 fi
 
@@ -121,12 +121,12 @@ case "$GOHOSTARCH" in
 386) mflag=-m32;;
 amd64) mflag=-m64;;
 esac
-if [ "$(uname)" == "Darwin" ]; then
+if [ "$(uname)" = "Darwin" ]; then
 	# golang.org/issue/5261
 	mflag="$mflag -mmacosx-version-min=10.6"
 fi
 # if gcc does not exist and $CC is not set, try clang if available.
-if [ -z "$CC" -a -z "$(type -t gcc)" -a -n "$(type -t clang)" ]; then
+if [ -z "$CC" -a -z "$(which gcc)" -a -n "$(which clang)" ]; then
 	export CC=clang CXX=clang++
 fi
 ${CC:-gcc} $mflag -O2 -Wall -Werror -o cmd/dist/dist -Icmd/dist "$DEFGOROOT" cmd/dist/*.c
