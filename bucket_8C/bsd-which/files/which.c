#include <sys/stat.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

static void     usage(void);
static int      print_matches(char *, char *);

int    silent;
int    allpaths;

int
main(int argc, char **argv)
{
       char *p, *path;
       ssize_t pathlen;
       int opt, status;

       status = EXIT_SUCCESS;

       while ((opt = getopt(argc, argv, "as")) != -1) {
               switch (opt) {
               case 'a':
                       allpaths = 1;
                       break;
               case 's':
                       silent = 1;
                       break;
               default:
                       usage();
                       break;
               }
       }

       argv += optind;
       argc -= optind;

       if (argc == 0)
	     usage();
	
       if ((p = getenv("PATH")) == NULL)
               exit(EXIT_FAILURE);
       pathlen = strlen(p) + 1;
       path = malloc(pathlen);
       if (path == NULL)
               err(EXIT_FAILURE, "malloc failed");

       while (argc > 0) {
               memcpy(path, p, pathlen);

               if (strlen(*argv) >= FILENAME_MAX ||
                   print_matches(path, *argv) == -1)
                       status = EXIT_FAILURE;

               argv++;
               argc--;
       }

       exit(status);
}

static void
usage(void)
{
       fprintf(stderr, "usage: which [-as] program ...\n");
       exit(EXIT_FAILURE);
}

static int
is_there(const char *candidate)
{
       struct stat fin;

       /* XXX work around access(2) false positives for superuser */
       if (access(candidate, X_OK) == 0 &&
           stat(candidate, &fin) == 0 &&
           S_ISREG(fin.st_mode) &&
           (getuid() != 0 ||
           (fin.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) != 0)) {
               if (!silent)
                       printf("%s\n", candidate);
               return (1);
       }
       return (0);
}

static int
print_matches(char *path, char *filename)
{
       char candidate[PATH_MAX];
       const char *d;
       int found;

       if (strchr(filename, '/') != NULL)
               return (is_there(filename) ? 0 : -1);
       found = 0;
       while ((d = strsep(&path, ":")) != NULL) {
               if (*d == '\0')
                       d = ".";
               if (snprintf(candidate, sizeof(candidate), "%s/%s", d,
                   filename) >= (int)sizeof(candidate))
                       continue;
               if (is_there(candidate)) {
                       found = 1;
                       if (!allpaths)
                               break;
               }
       }
       return (found ? 0 : -1);
}

