--- Source/JavaScriptCore/runtime/PropertyTable.h.orig	2026-02-19 21:54:11 UTC
+++ Source/JavaScriptCore/runtime/PropertyTable.h
@@ -181,7 +181,7 @@ private:
     template<typename Index, typename Entry>
     void reinsert(Index*, Entry*, const ValueType& entry);
 
-    static bool canFitInCompact(const ValueType& entry) { return entry.offset() <= UINT8_MAX; }
+    static bool canFitInCompact(const ValueType& entry) { return static_cast<unsigned>(entry.offset()) <= UINT8_MAX; }
 
     // Rehash the table. Used to grow, or to recover deleted slots.
     void rehash(VM&, unsigned newCapacity, bool canStayCompact);
