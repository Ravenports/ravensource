__BEGIN_DECLS
char *SHA_End(SHA_CTX *, char *);
char *SHA_File(const char *, char *);
char *SHA_FileChunk(const char *, char *, off_t, off_t);
char *SHA_Data(const void *, unsigned int, char *);
char *SHA1_End(SHA_CTX *, char *);
char *SHA1_File(const char *, char *);
char *SHA1_FileChunk(const char *, char *, off_t, off_t);
char *SHA1_Data(const void *, unsigned int, char *);
__END_DECLS
