--- protolib/src/common/protoAddress.cpp.orig	2018-07-20 21:58:26 UTC
+++ protolib/src/common/protoAddress.cpp
@@ -552,6 +552,9 @@ bool ProtoAddress::SetSockAddr(const str
     }
 }  // end ProtoAddress:SetAddress()
 
+#undef _SOCKLEN_T
+#undef _SOCKLEN_T_DECLARED
+
 /**
 *
 * @brief Initializes the address from the buffer contents
