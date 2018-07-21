--- protolib/src/common/protoPktIP.cpp.orig	2018-07-20 22:06:04 UTC
+++ protolib/src/common/protoPktIP.cpp
@@ -339,7 +339,7 @@ int ProtoPktIPv4::Option::GetLengthByTyp
         case EOOL:
         case NOP:
             return 1;
-        case SEC:
+        case SECXX:
             return 11;
         case SID:
         case MTUP:
@@ -354,7 +354,7 @@ int ProtoPktIPv4::Option::GetLengthByTyp
         case TS:
         case TR:
         case SDB:
-        case EIP:
+        case EIPXX:
         case CIPSO:
             return LENGTH_VARIABLE; // indicates variable length
         // unsupported options 
@@ -371,7 +371,7 @@ bool ProtoPktIPv4::Option::IsMutable(Typ
         // Immutable options
         case EOOL:
         case NOP:
-        case SEC:
+        case SECXX:
         case ESEC:
         case CIPSO:
         case RTRALT:
