#ifndef _SYMTAB_H_
#define _SYMTAB_H_

__BEGIN_DECLS
typedef struct symtab symtab_t;

void symtab_destroy(symtab_t *);
symtab_t * symtab_create(int, int, int);
int symtab_find(const symtab_t *, const void *, Dl_info *);
__END_DECLS

#endif /* _SYMTAB_H_ */
