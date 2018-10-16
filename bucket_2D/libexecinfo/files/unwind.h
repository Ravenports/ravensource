#ifndef _UNWIND_H_
#define _UNWIND_H_

struct _Unwind_Context;
struct _Unwind_Exception;
typedef int _Unwind_Reason_Code;
typedef void *_Unwind_Ptr;
typedef long _Unwind_Word;

typedef _Unwind_Reason_Code
    (*_Unwind_Trace_Fn)(struct _Unwind_Context *, void *);
#ifdef notyet
typedef _Unwind_Reason_Code
    (*_Unwind_Stop_Fn)(struct _Unwind_Context *, void *);
#endif

_Unwind_Reason_Code	 _Unwind_Backtrace(_Unwind_Trace_Fn, void *);
void 			 _Unwind_DeleteException(struct _Unwind_Exception *);
void 	       		*_Unwind_FindEnclosingFunction(void *);
#ifdef notyet
_Unwind_Reason_Code 	 _Unwind_ForcedUnwind(struct _Unwind_Exception *,
    _Unwind_Stop_fn, void *);
#endif
_Unwind_Word		 _Unwind_GetCFA(struct _Unwind_Context *);
_Unwind_Ptr		 _Unwind_GetDataRelBase(struct _Unwind_Context *);
_Unwind_Word 		 _Unwind_GetGR(struct _Unwind_Context *, int);
_Unwind_Ptr		 _Unwind_GetIP(struct _Unwind_Context *);
_Unwind_Ptr		 _Unwind_GetIPInfo(struct _Unwind_Context *, int *);
void 			*_Unwind_GetLanguageSpecificData(
    struct _Unwind_Context *);
_Unwind_Ptr		 _Unwind_GetRegionStart(struct _Unwind_Context *);
_Unwind_Ptr		 _Unwind_GetTextRelBase(struct _Unwind_Context *);
_Unwind_Reason_Code	 _Unwind_RaiseException(struct _Unwind_Exception *);
void			 _Unwind_Resume(struct _Unwind_Exception *);
_Unwind_Reason_Code	 _Unwind_Resume_or_Rethrow(struct _Unwind_Exception *);
void			 _Unwind_SetGR(struct _Unwind_Context *, int,
    _Unwind_Ptr);
void			 _Unwind_SetIP(struct _Unwind_Context *, _Unwind_Ptr);
#endif /* _UNWIND_H_ */
