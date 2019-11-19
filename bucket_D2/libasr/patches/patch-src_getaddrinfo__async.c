--- src/getaddrinfo_async.c.orig	2019-09-28 14:09:47 UTC
+++ src/getaddrinfo_async.c
@@ -144,7 +144,7 @@ getaddrinfo_async_run(struct asr_query *
 		}
 
 		if (as->as.ai.hostname && as->as.ai.hostname[0] == '\0') {
-			ar->ar_gai_errno = EAI_NODATA;
+			ar->ar_gai_errno = EAI_NONAME;
 			async_set_state(as, ASR_STATE_HALT);
 			break;
 		}
@@ -259,7 +259,7 @@ getaddrinfo_async_run(struct asr_query *
 				}
 			}
 			if (ar->ar_gai_errno == 0 && as->as_count == 0) {
-				ar->ar_gai_errno = EAI_NODATA;
+				ar->ar_gai_errno = EAI_NONAME;
 			}
 			async_set_state(as, ASR_STATE_HALT);
 			break;
@@ -442,7 +442,7 @@ getaddrinfo_async_run(struct asr_query *
 		if (as->as_flags & ASYNC_AGAIN)
 			ar->ar_gai_errno = EAI_AGAIN;
 		else
-			ar->ar_gai_errno = EAI_NODATA;
+			ar->ar_gai_errno = EAI_NONAME;
 		async_set_state(as, ASR_STATE_HALT);
 		break;
 
