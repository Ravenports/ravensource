--- libarchive/archive_read_support_format_cpio.c.orig	2026-07-28 09:30:38 UTC
+++ libarchive/archive_read_support_format_cpio.c
@@ -203,7 +203,9 @@ static int	archive_read_format_cpio_read
 static int	archive_read_format_cpio_read_header(struct archive_read *,
 		    struct archive_entry *);
 static int	archive_read_format_cpio_skip(struct archive_read *);
+#if !defined(__NetBSD__)
 static int64_t	be32dec(const unsigned char *);
+#endif
 static int	find_odc_header(struct archive_read *);
 static int	find_newc_header(struct archive_read *);
 static int	header_bin_be(struct archive_read *, struct cpio *,
@@ -218,7 +220,9 @@ static int	header_afiol(struct archive_r
 		    struct archive_entry *, size_t *, size_t *);
 static int	is_octal(const char *, size_t);
 static int	is_hex(const char *, size_t);
+#if !defined(__NetBSD__)
 static int64_t	le32dec(const unsigned char *);
+#endif
 static int	record_hardlink(struct archive_read *a,
 		    struct cpio *cpio, struct archive_entry *entry);
 
@@ -1013,6 +1017,7 @@ archive_read_format_cpio_cleanup(struct
 	return (ARCHIVE_OK);
 }
 
+#if !defined(__NetBSD__)
 static int64_t
 le32dec(const unsigned char *p)
 {
@@ -1024,6 +1029,7 @@ be32dec(const unsigned char *p)
 {
 	return ((int64_t)archive_be16dec(p) << 16) | archive_be16dec(p + 2);
 }
+#endif
 
 /*
  * Note that this implementation does not (and should not!) obey
