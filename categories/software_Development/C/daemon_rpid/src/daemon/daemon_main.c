/*
 * mtuliod.c
 *
 *  Created on: 18 de out de 2015
 *      Author: mtulio
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <getopt.h>

#include <daemon.h>
#include <mtd_lib.h>
#include <daemon_stdout.h>
#include <daemon_signal.h>
//#include <daemon_config.h>

/* Global config */
daemon_cfg_t *daemon_cfg;

/* Global options */
daemon_opt_t *daemon_opt;

/* Global return control */
short int ret = -1;

/**********************************************************/
/*
 *  Initialize main configuration reading from file and
 *  setting up structures.
 *
 * */
int daemon_initConfig (void)
{
	//int ret = -1;

	/* Server config file */
	if (!daemon_cfg) {
		daemon_cfg = (daemon_cfg_t *) malloc (sizeof(daemon_cfg_t));
		memset (daemon_cfg, 0, sizeof (daemon_cfg_t));
	}

	if (!daemon_opt) {
		daemon_opt = (daemon_opt_t *) malloc (sizeof(daemon_opt_t));
		memset (daemon_opt, 0, sizeof(daemon_opt_t));
	}


	/* Might to be read from command line */
	if (mtd_lib_fileExist ("/etc/mtuliod/mtuliod.conf") == RET_OK) {
		sprintf (daemon_cfg->config_file, "/etc/mtuliod/mtuliod.conf");

	} else {
		dm_stdout_print ("#% ERROR - Configuration file was not found\n");
		return (-1);

	}

	sprintf (daemon_cfg->log_file, "mtuliod.log");
	daemon_opt->log = FLAG_ENABLED;

	dm_stdout_print ("\t*** Starting MTULIOd Server *** \n");

	/* Load configuration file  */
//	ret = dm_config_main (daemon_cfg);
//	if (ret != 0) {
//		dm_stdout_print ("#% ERROR - opening config file\n");
//		return ret;
//	}

	return 0;
}

/* Clean config / free structs */
void daemon_end (void)
{
	//mtd_stdout_print("#>> Cleaning server config <<#\n");

	/* Free structures */
	if (daemon_cfg)
		free (daemon_cfg);

	if (daemon_opt)
		free (daemon_opt);

}

/****************************/
/* options using getopt. */
static struct option longopts[] =
{
  { "daemon",      no_argument,       NULL, 'd'},
  { "config_file", required_argument, NULL, 'f'},
  { "pid_file",    required_argument, NULL, 'i'},
  { "log_file",    required_argument, NULL, 'l'},
  { "help",        no_argument,       NULL, 'h'},
  { "version",     no_argument,       NULL, 'v'},
  { 0 }
};

/* Help information display. */
static void daemon_mainUsage (int status)
{
      printf ("Usage : %s [OPTION...]\n\
Daemon which manages MTuliod.\n\n\
-d, --daemon       Runs in daemon mode\n\
-f, --config_file  Set configuration file name\n\
-i, --pid_file     Set process identifier file name\n\
-l, --log_file     Set log file name\n\
-v, --version      Print program version\n\
-h, --help         Display this help and exit\n\
\n\
Report bugs to 'git@mtulio.eng.br'\n");

  exit (status);
}

/*
* Main function - might to be change when daemon function will be created.
* @param argc number of arguments in argv vector
* @param argv vector with arguments sent by command line
* @return a int to OS with status of execution program, zero is success
*/
int daemon_main (int argc , char *argv[])
{

	int arg_daemon_mode, arg_bind_port;
	char *arg_config_file, *arg_pid_file, *arg_log_file;
	arg_config_file = arg_pid_file = arg_log_file = NULL;
	arg_bind_port = arg_daemon_mode = 0;

  /* Command line option parse. */
  while (1) {
    int opt;
    opt = getopt_long (argc, argv, "df:il:h:v", longopts, 0);
    if (opt == EOF)
    	break;

    switch (opt)
	{
	  case 0:
		break;
      case 'd':
        arg_daemon_mode = 1;
        break;
	  case 'f':
		/*TODO: get argument string */
		arg_config_file = optarg;
		break;
	  case 'i':
		arg_pid_file = optarg;
		break;
	  case 'l':
		arg_log_file = optarg;
		break;
	  case 'v':
		printf ("%s: %s\n", PROG_NAME, PROG_VERSION);
		exit (0);
		break;
	  case 'h':
		daemon_mainUsage (0);
		break;
	  default:
		daemon_mainUsage (1);
	    break;
	  }
	}

  /* Show args */
//  printf("ARGS: arg_daemon_mode[%d], arg_file_config[%s], arg_file_pid[%s]\n",
//		  arg_daemon_mode,
//		  arg_config_file,
//		  arg_pid_file);

	/* Create a daemon */
	if (arg_daemon_mode == 1) {

		if ( (arg_config_file == NULL) ) {
			printf(" # CONFIG file option must be set. See help for details. \n");
			exit (1);

		} else {
			/* Check config file exists */
			if ( mtd_lib_fileExist(arg_config_file) != RET_OK ) {
				printf (" # CONFIG file [%s] not found in your system. \n", arg_config_file);
				exit (RET_ERR);
			}
			/* TODO: check syntax of config file */

			printf (" # Using config file [%s], ignoring other arguments.\n", arg_config_file);
		}

		/* Create a Daemon */
		ret = mtd_lib_daemon_init (1, 1);
		if ( (ret) < 0 ) {
			printf (" '%s': Starting daemon ... ERROR ", "mtuliod");
			dm_stdout_msg (ret);
		} else {
			printf (" '%s': Starting daemon ... PID %d \n", "mtuliod", ret);
		}
	}
	else {
		if ( (arg_pid_file == NULL) ||
				(arg_log_file == NULL) ) {

			printf (" # Please inform arguments or run as a daemon with config file \n");
			exit (1);

		}

	}

	/* Init main config file */
	if ( (ret = daemon_initConfig()) != 0 )
		goto GT_EXIT;

	/* Init System Signals */
	dm_signal_init ();



	/* END */
	GT_EXIT:

	/* Free structures */
	daemon_end();

	exit (ret);
}
