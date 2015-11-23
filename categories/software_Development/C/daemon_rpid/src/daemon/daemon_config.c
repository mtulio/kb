
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <daemon.h>
#include <mtd_lib.h>
#include <daemon_stdout.h>
#include <daemon_config.h>


/*
* Read main server config file and return it to struct.
* @param mtd_config is a struct with server configuration file
* @see main()
* @return a int with status of operation
*/
int dm_config_main (daemon_cfg_t *daemon_cfg)
{
	FILE *fd_config;
	char str_log[MAX_BUFF_SIZE];
	bzero (str_log, sizeof(str_log));

	/* Check file exist */
	fd_config = fopen (daemon_cfg->config_file, "r");
	if (fd_config) {
		sprintf (str_log, " # Configuration file was found [%s]", daemon_cfg->config_file);
		dm_stdout_print (str_log);
		if (fd_config)
			fclose (fd_config);
	} else {
		sprintf (str_log, " %% Unable to find config file [%s]\n", daemon_cfg->config_file);
		dm_stdout_print (str_log);
		return EXIT_ERR;
	}

	/* Reading data from file */
	sprintf (str_log, " reading...\n");
	dm_stdout_print (str_log);

	if (dm_config_readData (daemon_cfg) != 0 )
			return RET_ERR;

	/* End closing all pointers */
	finish:

	return RET_OK;
}

/*
* Function to read data from config file.
* @param mtd_config is a struct with server configuration file
* @see mtd_srv_config_main()
* @return a int with status of operation
*/
int dm_config_readData (daemon_cfg_t *daemon_cfg)
{
	FILE *fd_config;
	int ret = 0;

	char *str_attr;
	char *str_value;
	char str_buff[MAX_BUFF_SIZE];
	char str_log[MAX_BUFF_SIZE];

	memset (str_buff, 0, sizeof(str_buff));
	str_attr = (char *) malloc (sizeof(char)*MAX_CONFIG_SIZE_ATTR);
	str_value = (char *) malloc (sizeof(char)*MAX_CONFIG_SIZE_VALUE);
	bzero (str_attr, sizeof(str_attr) );
	bzero (str_value, sizeof(str_value) );

	/* Read file */
	fd_config = fopen (daemon_cfg->config_file, "r");
	if (fd_config) {

		// read each line
		while (fgets (str_buff, MAX_BUFF_SIZE, fd_config))
		{
			memset (str_attr, 0, sizeof(str_attr));
			memset (str_value, 0, sizeof(str_value));
			//printf(" [config_file] line: %s ", str_buff);

			if (mtd_lib_strings_lineIsEmpty (str_buff) == RET_OK)
				continue;
			if (mtd_lib_strings_lineIsComment (str_buff) == RET_OK)
				continue;

			if (mtd_lib_strings_splitByToken (str_buff, "=", str_attr, str_value) == 0) {

				mtd_lib_strings_trimNewLine (str_attr);
				mtd_lib_strings_trimNewLine (str_value);

				if (strncmp (str_attr, "LOG_FILE", strlen("LOG_FILE")) == 0) { // LOG_FILE
					strcpy (daemon_cfg->log_file, str_value);

					if (mtd_lib_fileExist (daemon_cfg->log_file) != RET_OK) {
						strcpy (daemon_cfg->log_file, "mtuliod.log");
					}
					//printf(" '-> LOG_FILE \t\t = [%s] \n", mtd_config->log_file);
					sprintf (str_log, " '-> LOG_FILE \t\t = [%s] \n", daemon_cfg->log_file);
					dm_stdout_print (str_log);
				}
			}
		}
		fclose (fd_config);
	} else {
		sprintf (str_log, " #% [config_file] unable to open file: %s ", daemon_cfg->config_file);
		dm_stdout_print (str_log);
		ret = RET_ERR;
		goto GT_FINAL;
	}

	//printf("ret[%d]", mtd_srv_config_file_load (mtd_config));
	ret = RET_OK;

	GT_FINAL:
	if (str_attr)
		free (str_attr);
	if (str_value)
		free (str_value);

	return ret;
}
