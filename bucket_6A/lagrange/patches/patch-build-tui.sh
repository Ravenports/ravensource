--- build-tui.sh.orig	2022-05-06 09:47:39 UTC
+++ build-tui.sh
@@ -14,8 +14,10 @@
 #
 # You can customize the install directory prefix here and build type here:
 
-INSTALL_PREFIX="/usr/local"
+INSTALL_PREFIX="__STAGEDIR____PREFIX__"
 CMAKE_BUILD_TYPE="Release"
+export PKG_CONFIG_PATH=/__PREFIX__/openssl11/lib/pkgconfig
+export LDFLAGS="-L/__PREFIX__/openssl11/lib -Wl,-rpath,/__PREFIX__/openssl11/lib"
 
 #-----------------------------------------------------------------------------
 
@@ -71,8 +73,5 @@ cmake --build . || exit 1
 
 echo "-----"
 echo "clagrange and resources.lgr can be found in 'build-tui'."
-read -p "Do you want to install them to ${INSTALL_PREFIX}? [yN] " CONFIRMED
-if [ "${CONFIRMED}" = "y" ]; then
-    cmake --install .
-    exit
-fi
+cmake --install .
+exit
