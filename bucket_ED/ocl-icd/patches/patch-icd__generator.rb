--- icd_generator.rb.orig	2023-06-02 21:36:20 UTC
+++ icd_generator.rb
@@ -561,7 +561,7 @@ EOF
   end
 
   def self.generate_ocl_icd_loader_map
-    ocl_icd_loader_map = "/**\n#{$license}\n*/\n\n"
+    ocl_icd_loader_map = "\n"
     prev_version=""
     $versions_entries.keys.sort.each { |version|
       ocl_icd_loader_map += "OPENCL_#{version.sub('_','.')} {\n";
