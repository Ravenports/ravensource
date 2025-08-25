--- deps/openssl/openssl/util/perl/OpenSSL/config.pm.orig	2025-08-14 20:34:23 UTC
+++ deps/openssl/openssl/util/perl/OpenSSL/config.pm
@@ -807,6 +807,7 @@ EOF
       [ 'ia64-.*-openbsd.*',      { target => "BSD-nodef-ia64" } ],
       [ 'ia64-.*-.*bsd.*',        { target => "BSD-ia64" } ],
       [ 'x86_64-.*-dragonfly.*',  { target => "BSD-x86_64" } ],
+      [ 'x86_64-.*-*bsd.*',       { target => "BSD-x86_64" } ],
       [ 'amd64-.*-openbsd.*',     { target => "BSD-nodef-x86_64" } ],
       [ 'amd64-.*-.*bsd.*',       { target => "BSD-x86_64" } ],
       [ 'arm64-.*-.*bsd.*',       { target => "BSD-aarch64" } ],
