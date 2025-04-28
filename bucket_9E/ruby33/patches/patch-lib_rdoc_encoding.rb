$NetBSD: patch-lib_rdoc_encoding.rb,v 1.1 2023/01/21 13:51:23 taca Exp $

* Always convert "\r\n" to "\n" since it cause rdoc processing error.

--- lib/rdoc/encoding.rb.orig	2025-04-09 09:23:04 UTC
+++ lib/rdoc/encoding.rb
@@ -31,7 +31,7 @@ module RDoc::Encoding
 
   def self.read_file filename, encoding, force_transcode = false
     content = File.open filename, "rb" do |f| f.read end
-    content.gsub!("\r\n", "\n") if RUBY_PLATFORM =~ /mswin|mingw/
+    content.gsub!("\r\n", "\n")
 
     utf8 = content.sub!(/\A\xef\xbb\xbf/, '')
 
