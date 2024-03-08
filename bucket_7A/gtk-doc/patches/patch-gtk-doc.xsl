--- gtk-doc.xsl.orig	2024-03-05 18:09:52 UTC
+++ gtk-doc.xsl
@@ -8,7 +8,7 @@
   <!-- http://www.sagehill.net/docbookxsl/Chunking.html#FastChunking says we should use
        "chunkfast.xsl", but I can't see a difference. Also it is not clear whether
        one should still set "chunk.fast". Again, no meassuable difference. -->
-  <xsl:import href="http://docbook.sourceforge.net/release/xsl/current/html/chunk.xsl"/>
+  <xsl:import href="file://%%LOCALBASE%%/share/xsl/docbook/html/chunk.xsl"/>
   <xsl:include href="devhelp2.xsl"/>
   <xsl:include href="version-greater-or-equal.xsl"/>
 
@@ -70,7 +70,7 @@
        this at least avoid the re-evaluation -->
   <xsl:template name="l10n.language">en</xsl:template>
 
-  <xsl:param name="gtkdoc.l10n.xml" select="document('http://docbook.sourceforge.net/release/xsl/current/common/en.xml')"/>
+  <xsl:param name="gtkdoc.l10n.xml" select="document('file://%%LOCALBASE%%/share/xsl/docbook/common/en.xml')"/>
 
   <xsl:key name="gtkdoc.gentext.key" match="l:gentext[@key]" use="@key"/>
   <xsl:key name="gtkdoc.context.key" match="l:context[@name]" use="@name"/>
