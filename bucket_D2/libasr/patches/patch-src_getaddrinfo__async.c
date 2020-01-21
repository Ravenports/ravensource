--- src/getaddrinfo_async.c.orig	2020-01-17 13:59:24 UTC
+++ src/getaddrinfo_async.c
@@ -147,7 +147,7 @@ getaddrinfo_async_run(struct asr_query *
 		}
 
 		if (as->as.ai.hostname && as->as.ai.hostname[0] == '\0') {
-			ar->ar_gai_errno = EAI_NODATA;
+			ar->ar_gai_errno = EAI_NONAME;
 			async_set_state(as, ASR_STATE_HALT);
 			break;
 		}
@@ -262,7 +262,7 @@ getaddrinfo_async_run(struct asr_query *
 				}
 			}
 			if (ar->ar_gai_errno == 0 && as->as_count == 0) {
-				ar->ar_gai_errno = EAI_NODATA;
+				ar->ar_gai_errno = EAI_NONAME;
 			}
 			async_set_state(as, ASR_STATE_HALT);
 			break;
@@ -445,7 +445,7 @@ getaddrinfo_async_run(struct asr_query *
 		if (as->as_flags & ASYNC_AGAIN)
 			ar->ar_gai_errno = EAI_AGAIN;
 		else
-			ar->ar_gai_errno = EAI_NODATA;
+			ar->ar_gai_errno = EAI_NONAME;
 		async_set_state(as, ASR_STATE_HALT);
 		break;
 
