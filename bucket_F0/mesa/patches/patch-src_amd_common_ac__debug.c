--- src/amd/common/ac_debug.c.orig	2018-12-13 14:02:20 UTC
+++ src/amd/common/ac_debug.c
@@ -560,6 +560,10 @@ void ac_parse_ib_chunk(FILE *f, uint32_t
 		       unsigned trace_id_count, enum chip_class chip_class,
                        ac_debug_addr_callback addr_callback, void *addr_callback_data)
 {
+#ifdef __sun__
+	printf("\nac_parse_ib_chunk: open_memstream unsupported on solaris");
+	exit (1);
+#else
 	struct ac_ib_parser ib = {};
 	ib.ib = ib_ptr;
 	ib.num_dw = num_dw;
@@ -585,6 +589,7 @@ void ac_parse_ib_chunk(FILE *f, uint32_t
 		printf("\nPacket ends after the end of IB.\n");
 		exit(1);
 	}
+#endif
 }
 
 /**
