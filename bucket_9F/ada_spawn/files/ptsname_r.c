#ifdef __DragonFly__
# define __NEEDS_PTSNAME_R__
#endif
#ifdef __FreeBSD__
# include <sys/param.h>
# if __FreeBSD_version < 1203000
#  define __NEEDS_PTSNAME_R__
# endif
#endif

#ifdef __NEEDS_PTSNAME_R__

#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Store at most BUFLEN characters of the pathname of the slave pseudo
   terminal associated with the master FD is open on in BUF.
   Return 0 on success, otherwise an error number.  */
int
__ptsname_r (int fd, char *buf, size_t buflen)
{
  int saved_errno = errno;
  char tmpbuf[5 + 4 + 10 + 1];
  int ret;
  int n;
  if (buf == NULL)
    {
      errno = EINVAL;
      return errno;
    }
  /* The result of fdevname_r is typically of the form ptm/N.  */
  ret = fdevname_r (fd, tmpbuf + 5, sizeof (tmpbuf) - 5);
  if (ret < 0 || strncmp (tmpbuf + 5, "ptm/", 4) != 0)
    {
      errno = ENOTTY;
      return errno;
    }
  /* Turn it into /dev/pts/N.  */
  memcpy (tmpbuf, "/dev/pts/", 5 + 4);
  n = strlen (tmpbuf);
  if (n >= buflen)
    {
      errno = ERANGE;
      return errno;
    }
  memcpy (buf, tmpbuf, n + 1);
  /* Don't do a final stat(), since the file name /dev/pts/N does not actually
     exist.  */
  errno = saved_errno;
  return 0;
}

#else

#include <stdlib.h>

int
__ptsname_r (int fd, char *buf, size_t buflen)
{
  return ptsname_r (fd, buf, buflen);
}

#endif
