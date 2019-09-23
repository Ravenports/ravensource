--- modules/speller/default/affix.cpp.orig	2019-07-10 09:17:18 UTC
+++ modules/speller/default/affix.cpp
@@ -796,7 +796,10 @@ bool AffixMgr::suffix_check (const Looku
     if (se->check(linf, word, ci, gi, sfxopts, ppfx)) return true;
     se = se->next;
   }
-  
+
+  if (word.size() == 0)
+    return false;
+
   // now handle the general case
   byte sp = *((const byte *)(word + word.size() - 1));
   SfxEntry * sptr = sStart[sp];
