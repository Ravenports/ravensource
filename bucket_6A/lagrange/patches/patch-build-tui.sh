--- build-tui.sh.orig	2022-06-30 05:46:44 UTC
+++ build-tui.sh
@@ -14,23 +14,15 @@
 #
 # You can customize the install directory prefix here and build type here:
 
-INSTALL_PREFIX="/usr/local"
+INSTALL_PREFIX="__PREFIX__"
 CMAKE_BUILD_TYPE="Release"
+export PKG_CONFIG_PATH=/__PREFIX__/openssl11/lib/pkgconfig
+export LDFLAGS="-L/__PREFIX__/openssl11/lib -Wl,-rpath,/__PREFIX__/openssl11/lib"
 
 echo "\nThis script will build and optionally install clagrange with"
 echo "statically linked the_Foundation and SEALCurses. First, let's configure"
 echo "the build.\n"
 
-read -p "Build type? [${CMAKE_BUILD_TYPE}] " INPUT
-if [ "${INPUT}." != "." ]; then
-    CMAKE_BUILD_TYPE=${INPUT}
-fi
-
-read -p "Install prefix? [${INSTALL_PREFIX}] " INPUT
-if [ "${INPUT}." != "." ]; then
-    INSTALL_PREFIX=${INPUT}
-fi
-
 if [ ! -d lib/sealcurses ]; then
     read -p "'lib/sealcurses' not found. Clone with Git? [Yn] " INPUT
     if [ "${INPUT}." = "n." ]; then
@@ -91,14 +83,11 @@ cmake .. \
     -DENABLE_HARFBUZZ=NO \
     -DENABLE_POPUP_MENUS=NO \
     -DENABLE_IDLE_SLEEP=NO \
+    -DCMAKE_SKIP_RPATH:BOOL=TRUE \
     -Dthe_Foundation_DIR="${BUILD_DIR}/lib/cmake/the_Foundation" \
     $*
 cmake --build . || exit 1
 
 echo "-----"
 echo "clagrange and resources.lgr can be found in 'build-tui'."
-read -p "Do you want to install them to ${INSTALL_PREFIX}? (sudo) [yN] " CONFIRMED
-if [ "${CONFIRMED}" = "y" ]; then
-    sudo cmake --install .
-    exit
-fi
+exit
