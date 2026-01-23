From NetBSD (ruby 3.4)

* Always convert "\r\n" to "\n" since it cause rdoc processing error.

--- .bundle/gems/rdoc-7.0.3/lib/rdoc/encoding.rb.orig	2026-01-13 02:02:42 UTC
+++ .bundle/gems/rdoc-7.0.3/lib/rdoc/encoding.rb
@@ -31,7 +31,7 @@ module RDoc::Encoding
 
   def self.read_file(filename, encoding, force_transcode = false)
     content = File.open filename, "rb" do |f| f.read end
-    content.gsub!("\r\n", "\n") if RUBY_PLATFORM =~ /mswin|mingw/
+    content.gsub!("\r\n", "\n")
 
     utf8 = content.sub!(/\A\xef\xbb\xbf/, '')
 
