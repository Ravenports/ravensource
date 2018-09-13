#ifndef _SHA_H_
#define _SHA_H_

#include <sys/cdefs.h>
#include <sys/types.h>	/* XXX switch to machine/stdint.h and __ types */
#include <openssl/sha.h>

#define	SHA_BLOCK	16
#define	SHA_LENGTH_BLOCK 8

#define	SHA1_CTX	SHA_CTX

__BEGIN_DECLS
/* these three are not included in libressl for reasons unknown */
int SHA_Init(SHA_CTX *c);
int SHA_Update(SHA_CTX *c, const void *data, size_t len);
int SHA_Final(unsigned char *md, SHA_CTX *c);

#if 0
char *SHA_End(SHA_CTX *, char *);
char *SHA_File(const char *, char *);
char *SHA_FileChunk(const char *, char *, off_t, off_t);
char *SHA_Data(const void *, unsigned int, char *);
char *SHA1_End(SHA_CTX *, char *);
char *SHA1_File(const char *, char *);
char *SHA1_FileChunk(const char *, char *, off_t, off_t);
char *SHA1_Data(const void *, unsigned int, char *);
#endif
__END_DECLS

#endif
