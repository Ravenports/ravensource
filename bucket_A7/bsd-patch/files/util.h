char		*fetchname(const char *, bool *, int);
int		backup_file(const char *);
int		move_file(const char *, const char *);
int		copy_file(const char *, const char *);
void		say(const char *, ...)
		    __attribute__((__format__(__printf__, 1, 2)));
void		fatal(const char *, ...)
		    __attribute__((__format__(__printf__, 1, 2)));
void		pfatal(const char *, ...)
		    __attribute__((__format__(__printf__, 1, 2)));
void		ask(const char *, ...)
		    __attribute__((__format__(__printf__, 1, 2)));
char		*savestr(const char *);
char		*xstrdup(const char *);
void		set_signals(int);
void		ignore_signals(void);
void		makedirs(const char *, bool);
void		version(void);
void		my_exit(int) __attribute__((noreturn));

/* in mkpath.c */
extern int mkpath(char *);
