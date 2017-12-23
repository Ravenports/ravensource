--- gi/pygi-info.c.orig	2017-10-13 10:01:53 UTC
+++ gi/pygi-info.c
@@ -162,9 +162,6 @@ _pygi_info_new (GIBaseInfo *info)
         case GI_INFO_TYPE_CONSTANT:
             type = &PyGIConstantInfo_Type;
             break;
-        case GI_INFO_TYPE_ERROR_DOMAIN:
-            type = &PyGIErrorDomainInfo_Type;
-            break;
         case GI_INFO_TYPE_UNION:
             type = &PyGIUnionInfo_Type;
             break;
@@ -481,7 +478,6 @@ _pygi_g_type_info_size (GITypeInfo *type
                 case GI_INFO_TYPE_INVALID:
                 case GI_INFO_TYPE_FUNCTION:
                 case GI_INFO_TYPE_CONSTANT:
-                case GI_INFO_TYPE_ERROR_DOMAIN:
                 case GI_INFO_TYPE_VALUE:
                 case GI_INFO_TYPE_SIGNAL:
                 case GI_INFO_TYPE_PROPERTY:
@@ -860,7 +856,6 @@ pygi_g_struct_info_is_simple (GIStructIn
                     case GI_INFO_TYPE_INVALID:
                     case GI_INFO_TYPE_FUNCTION:
                     case GI_INFO_TYPE_CONSTANT:
-                    case GI_INFO_TYPE_ERROR_DOMAIN:
                     case GI_INFO_TYPE_VALUE:
                     case GI_INFO_TYPE_SIGNAL:
                     case GI_INFO_TYPE_PROPERTY:
