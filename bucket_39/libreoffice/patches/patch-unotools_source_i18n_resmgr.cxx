--- unotools/source/i18n/resmgr.cxx.orig	2022-11-16 17:29:15 UTC
+++ unotools/source/i18n/resmgr.cxx
@@ -127,8 +127,13 @@ namespace Translate
         if (aFind != aCache.end())
             return aFind->second;
         boost::locale::generator gen;
+#if BOOST_VERSION < 108100
         gen.characters(boost::locale::char_facet);
         gen.categories(boost::locale::message_facet | boost::locale::information_facet);
+#else
+        gen.characters(boost::locale::char_facet_t::char_f);
+        gen.categories(boost::locale::category_t::message | boost::locale::category_t::information);
+#endif
 #if defined(ANDROID)
         OString sPath(OString(lo_get_app_data_dir()) + "/program/resource");
 #else
