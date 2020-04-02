--- protos.h.orig	2020-03-28 18:17:53 UTC
+++ protos.h
@@ -87,6 +87,7 @@ ADDRESS *mutt_get_address (ENVELOPE *, c
 ADDRESS *mutt_lookup_alias (const char *s);
 ADDRESS *mutt_remove_duplicates (ADDRESS *);
 ADDRESS *mutt_remove_xrefs (ADDRESS *, ADDRESS *);
+ADDRESS *mutt_reverse_address (ADDRESS *);
 ADDRESS *mutt_expand_aliases (ADDRESS *);
 ADDRESS *mutt_parse_adrlist (ADDRESS *, const char *);
 
