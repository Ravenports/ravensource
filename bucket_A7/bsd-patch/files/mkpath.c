#include <sys/types.h>
#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <string.h>

int	mkpath(char *);

/* Code taken directly from mkdir(1).

 * mkpath -- create directories.
 *	path     - path
 */
int
mkpath(char *path)
{
	struct stat sb;
	char *slash;
	int done = 0;

	slash = path;

	while (!done) {
		slash += strspn(slash, "/");
		slash += strcspn(slash, "/");

		done = (*slash == '\0');
		*slash = '\0';

		if (stat(path, &sb)) {
			if (errno != ENOENT || (mkdir(path, 0777) &&
			    errno != EEXIST)) {
				warn("%s", path);
				return (-1);
			}
		} else if (!S_ISDIR(sb.st_mode)) {
			warnx("%s: %s", path, strerror(ENOTDIR));
			return (-1);
		}

		*slash = '/';
	}

	return (0);
}

