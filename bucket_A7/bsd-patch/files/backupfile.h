/* When to make backup files. */
enum backup_type {
	/* Never make backups. */
	none,

	/* Make simple backups of every file. */
	simple,

	/*
	 * Make numbered backups of files that already have numbered backups,
	 * and simple backups of the others.
	 */
	numbered_existing,

	/* Make numbered backups of every file. */
	numbered
};

extern enum backup_type backup_type;
extern const char	*simple_backup_suffix;

char		*find_backup_file_name(const char *file);
enum backup_type get_version(const char *version);
