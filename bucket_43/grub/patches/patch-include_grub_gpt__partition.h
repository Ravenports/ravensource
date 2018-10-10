--- include/grub/gpt_partition.h.orig	2018-10-07 17:23:17.507896000 +0200
+++ include/grub/gpt_partition.h	2018-10-07 17:28:14.193831000 +0200
@@ -28,7 +28,7 @@
   grub_uint16_t data2;
   grub_uint16_t data3;
   grub_uint8_t data4[8];
-} __attribute__ ((aligned(8)));
+} GRUB_PACKED;
 typedef struct grub_gpt_part_type grub_gpt_part_type_t;
 
 #define GRUB_GPT_PARTITION_TYPE_EMPTY \
