
#include<stdio.h>

#include <daemon.h>
#include <daemon_stdout.h>

extern daemon_opt_t *daemon_opt;
extern daemon_cfg_t *daemon_cfg;

/* Print message on stdout (when daemon mode is not enabled)*/
void dm_stdout_print (char *line)
{
	FILE *fd;

	if (daemon_opt->daemon == FLAG_DISABLED)
		printf("%s", line);

	if (daemon_opt->log == FLAG_ENABLED) {
			fd = fopen (daemon_cfg->log_file, "a+");
			if (!fd) {
				printf(" %s() # Log file was not found [%s]",
						__FUNCTION__, daemon_cfg->config_file);
				return;
			}

			fprintf (fd, line);
			if (ferror(fd))
				printf(" %s() #% Error writing log file\n", __FUNCTION__);;

			if (fd)
				fclose (fd);
	}
    fflush (stdout);
}

/* Print error message */
void daemon_stdout_msg (int ret_code)
{
	switch (ret_code) {
	case RET_ERR_DM01:
		dm_stdout_print ("# ERROR DAEMON: fork failed\n");
		break;
	case RET_ERR_DM02:
		dm_stdout_print ("# ERROR DAEMON: setsid failed\n");
		break;
	default:
		dm_stdout_print ("# Unknown message\n");
	}
}
