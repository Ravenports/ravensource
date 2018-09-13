#ifndef MAC_SUPPORT_H
#define MAC_SUPPORT_H

#ifdef __APPLE__
long long	strtonum(const char *, long long, long long, const char **);
#endif

#endif /* MAC_SUPPORT_H */
