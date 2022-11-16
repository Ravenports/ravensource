--- deps/openssl/openssl/util/perl/OpenSSL/config.pm.orig	2022-11-14 02:26:04 UTC
+++ deps/openssl/openssl/util/perl/OpenSSL/config.pm
@@ -781,6 +781,7 @@ EOF
       [ 'sparc64-.*-.*bsd.*',     { target => "BSD-sparc64" } ],
       [ 'ia64-.*-.*bsd.*',        { target => "BSD-ia64" } ],
       [ 'x86_64-.*-dragonfly.*',  { target => "BSD-x86_64" } ],
+      [ 'x86_64-.*-*bsd.*',       { target => "BSD-x86_64" } ],
       [ 'amd64-.*-.*bsd.*',       { target => "BSD-x86_64" } ],
       [ 'arm64-.*-.*bsd.*',       { target => "BSD-aarch64" } ],
       [ '.*86.*-.*-.*bsd.*',
