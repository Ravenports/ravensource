#ifndef _EXECINFO_H_
#define _EXECINFO_H_

#include <stddef.h>

# ifndef __BEGIN_DECLS
#   ifdef __cplusplus
#     define __BEGIN_DECLS	extern "C" {
#     define __END_DECLS	}
#   else
#     define __BEGIN_DECLS
#     define __END_DECLS
#   endif
# endif

__BEGIN_DECLS
size_t backtrace(void **, size_t);
char **backtrace_symbols(void *const *, size_t);
int backtrace_symbols_fd(void *const *, size_t, int);
char **backtrace_symbols_fmt(void *const *, size_t, const char *);
int backtrace_symbols_fd_fmt(void *const *, size_t, int, const char *);
__END_DECLS

#endif /* _EXECINFO_H_ */
