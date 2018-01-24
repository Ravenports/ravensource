#include <libgen.h>
#include <string.h>
#include <stdlib.h>

const char *getprogname () {
    static const char *progname;

    if (progname == NULL) {
        const char *e = getexecname();
        if (e != NULL) {
            /* Have to make a copy since getexecname can return a readonly
               string, but basename expects to be able to modify its arg. */
            char *n = strdup(e);
            if (n != NULL) {
                progname = basename(n);
            }
        }
    }
    return progname;
}
