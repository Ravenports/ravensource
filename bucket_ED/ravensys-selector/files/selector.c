/*
 * This program will automatically exec another program as a function
 * of the program name (argument 0) and environment variables.
 * The primary function is to support solaris, but to convert
 * gnu-specific linker flags to solaris equivalents.  It can also
 * be used to force use of the gold linker for other platforms.
 *
 *   ENV. VAR    VALUE       command    EXECUTED
 *   -----------------------------------------------------
 *   LINKER      unset       ld         $BIN_PREFIX/bin/ld.sun
 *   LINKER      bfd         ld         $BIN_PREFIX/bin/ld.bfd
 *   LINKER      gold        ld         $BIN_PREFIX/bin/ld.gold
 *   LINKER      sun         ld         $BIN_PREFIX/bin/ld.sun
 *   LINKER      lld         ld         $BIN_PREFIX/bin/ld.lld
 *   LINKER      all else    ld         $BIN_PREFIX/bin/ld.sun
 *
 *   BIN_PREFIX = "/raven/toolchain" unless SWITCH_PREFIX is
 *   present in the environment (in which case, BIN_PREFIX is set
 *   to the value of that variable)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINKER_BFD     "ld.bfd"
#define LINKER_GOLD    "ld.gold"
#define LINKER_SUN     "ld.sun"
#define LINKER_LLD     "ld.lld"

#undef NELEM
#undef BIN_PREFIX_DEFAULT

/* Macro for array size */
#define NELEM(ary)      (sizeof(ary) / sizeof((ary)[0]))

/* Standard definition */
#define BIN_PREFIX_DEFAULT	"/raven/toolchain"

enum cmd_type { UNKNOWN, COMPILER, LINKER };

struct command {
	const char *cmd;
	enum cmd_type type;
};

static struct command commands[] = {
	{"ld",			LINKER},
	{"",			UNKNOWN}
};

int
main(int argc, char **argv)
{
	char ld_bfd[] = LINKER_BFD;
	char ld_gld[] = LINKER_GOLD;
	char ld_sun[] = LINKER_SUN;
	char ld_lld[] = LINKER_LLD;
	char *cmd;
	char *ldcmd = ld_sun;
	char *newargv[argc];
	char *sun_rpath  = "-R";
	char *sun_soname = "-h";
	char *sun_shared = "-G";
	char *sun_static = "-a";
	char *sun_script = "-M";
	char newcmd[1024];
	const char *ldver;
	const char *bin_prefix;
	struct command *cmds;
	int newx = 0;
	int x;

	/*
	 * Get the last path element of the program name being executed
	 */
	cmd = strrchr(argv[0], '/');
	if (cmd != NULL)
		cmd++;
	else
		cmd = argv[0];

	for (cmds = commands; cmds < &commands[NELEM(commands) - 1]; ++cmds) {
		if (strcmp(cmd, cmds->cmd) == 0)
			break;
	}
	if (cmds) {
		switch (cmds->type) {
		case COMPILER:
			printf ("COMPILER type unreachable\n");
			exit (1);
		case LINKER:
			ldver = getenv("LINKER");
			if (ldver != NULL) {
				if (strcmp(ldver, "sun") == 0)
					ldcmd = ld_sun;
				else if (strcmp(ldver, "gold") == 0)
					ldcmd = ld_gld;
				else if (strcmp(ldver, "bfd") == 0)
					ldcmd = ld_bfd;
				else if (strcmp(ldver, "lld") == 0)
					ldcmd = ld_lld;
			}
			cmd = ldcmd;
			break;
		default:
			printf ("Command name unmatched\n");
			exit (1);
		}
	}

	bin_prefix = getenv("SWITCH_PREFIX");
	if (bin_prefix == NULL)
		bin_prefix = BIN_PREFIX_DEFAULT;

	snprintf(newcmd, sizeof(newcmd), "%s/bin/%s", bin_prefix, cmd);

	/*
	 * Sun linker only : Filter out unrecognized arguments and
	 *                   Convert gnu-specific commands to sun equivalent
	 */
	if (cmd == ld_sun) {
		for (x = 0; x < argc; x++)
		{
			if (!(strcmp(argv[x], "--enable-new-dtags") == 0) &&
			    !(strcmp(argv[x], "--disable-new-dtags") == 0) &&
			    !(strcmp(argv[x], "--gc-keep-exported") == 0) &&
			    !(strcmp(argv[x], "--gc-sections") == 0) &&
			    !(strcmp(argv[x], "--no-gc-sections") == 0) &&
			    !(strcmp(argv[x], "--export-dynamic") == 0) &&
			    !(strcmp(argv[x], "--no-export-dynamic") == 0) &&
			    !(strcmp(argv[x], "-E") == 0))
			{
				     if (strcmp(argv[x], "-rpath") == 0)
					newargv[newx] = sun_rpath;
				else if (strcmp(argv[x], "-soname") == 0)
					newargv[newx] = sun_soname;
				else if (strcmp(argv[x], "-shared") == 0)
					newargv[newx] = sun_shared;
				else if (strcmp(argv[x], "-static") == 0)
					newargv[newx] = sun_static;
				else if (strcmp(argv[x], "--version-script") == 0)
					newargv[newx] = sun_script;
				else
					newargv[newx] = argv[x];
				newx++;
			}
		}
		for (x = newx; x < argc; x++)
			newargv[x] = NULL;

		newargv[0] = newcmd;
		execv(newcmd, newargv);
	} else {
		argv[0] = newcmd;
		execv(newcmd, argv);
	}

	/*
	 * Execution failed, so write out an error message
	 */
	printf ("Command execution failed: %s\n", newcmd);
	printf ("               arguments:");
	for (x = 1; x < argc; x++)
		printf (" %s", (cmd == ld_sun) ? newargv[x] : argv[x]);
	printf ("\n");
	exit (1);
}
