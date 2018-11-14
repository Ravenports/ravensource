--- Source/JavaScriptCore/bytecompiler/BytecodeGenerator.cpp.orig	2018-10-28 13:50:04 UTC
+++ Source/JavaScriptCore/bytecompiler/BytecodeGenerator.cpp
@@ -2920,8 +2920,7 @@ RegisterID* BytecodeGenerator::emitGetBy
             break;
         }
 
-        ASSERT(context.type() == ForInContext::StructureForInContextType);
-        StructureForInContext& structureContext = static_cast<StructureForInContext&>(context);
+        StructureForInContext& structureContext = context.asStructureForInContext();
         UnlinkedValueProfile profile = emitProfiledOpcode(op_get_direct_pname);
         instructions().append(kill(dst));
         instructions().append(base->index());
