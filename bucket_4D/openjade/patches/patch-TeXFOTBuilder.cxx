--- jade/TeXFOTBuilder.cxx.orig	2002-01-15 10:35:37 UTC
+++ jade/TeXFOTBuilder.cxx
@@ -88,6 +88,8 @@ public:
       value.convertString(nic_.placement);
       }
     ExtensionFlowObj *copy() const { return new PageFloatFlowObj(*this); }
+  public:
+    PageFloatFlowObj() {}
   private:
     PageFloatNIC nic_;
     StringC name_;
@@ -101,6 +103,8 @@ public:
       fotb.endPageFootnote();
     }
     ExtensionFlowObj *copy() const { return new PageFootnoteFlowObj(*this); }
+  public:
+    PageFootnoteFlowObj() {}
   private:
   };
   //////////////////////////////////////////////////////////////////////
