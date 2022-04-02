--- deps/openssl/openssl/util/perl/OpenSSL/config.pm.orig	2022-03-22 02:56:43 UTC
+++ deps/openssl/openssl/util/perl/OpenSSL/config.pm
@@ -753,6 +753,7 @@ EOF
       [ 'sparc64-.*-.*bsd.*',     { target => "BSD-sparc64" } ],
       [ 'ia64-.*-.*bsd.*',        { target => "BSD-ia64" } ],
       [ 'x86_64-.*-dragonfly.*',  { target => "BSD-x86_64" } ],
+      [ 'x86_64-.*-*bsd.*',       { target => "BSD-x86_64" } ],
       [ 'amd64-.*-.*bsd.*',       { target => "BSD-x86_64" } ],
       [ '.*86.*-.*-.*bsd.*',
         sub {
