/*
 * mtd_lib_daemon.c
 *
 *  Created on: 1 de nov de 2015
 *      Author: mtulio
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>	/*Daemon function */
#include <errno.h> /* errno */
#include <fcntl.h> /* O_RDWR */
#include <sys/stat.h> /* umask */

#include <daemon.h>
#include <mtd_lib.h>

/**********************************************************/
/* DAEMON (Disk and Execution Monitor).
 * Create a daemon from myself. ;)
 * nochdir set to 0 to change daemon home to / (root)
 * If noclose is zero, daemon() redirects standard input,
 * 	standard output and standard error to /dev/null; otherwise,
 * 	no changes are made to these file descriptors.
 * If nochdir is zero, daemon() changes the calling process's
 * 	current working directory to the root directory ("/"); otherwise,
 * 	the current working directory is left unchanged.
 *
 * return -1 to fork() failed
 * return -2 to setsid() failed
 * return SID - process IDentification
 * see man daemon();
 *
 * BASIC DAEMON STRUCTURE:
 *  - Fork off the parent process
 *  - Change file mode mask (umask)
 *  - Open any logs for writing
 *  - Create a unique Session ID (SID)
 *  - Change the current working directory to a safe place
 *  - Close standard file descriptors
 *  - Enter actual daemon code
 *
 * */
int mtd_lib_daemon_init (int nochdir, int noclose)
{
  /* Our process ID and Session ID */
  pid_t pid, sid;

  /* Fork off the parent process */
  pid = fork ();

  /* In case of fork is error. */
  if (pid < 0)
	  exit (RET_ERR_DM01);

  /* If we got a good PID, then
	we can exit the parent process. */
  if (pid > 0)
	  exit(RET_OK);

  /* Change the file mode mask */
  umask(0);

  /* Open any logs here */

  /* Create a new SID for the child process */
  sid = setsid();
  if (sid < 0) {
	  /* Log the failure */
	  printf("__FUNCTION__(%s) setsid().err\n", __FUNCTION__);
	  exit(EXIT_FAILURE);
   }

  /* Change the current working directory */
  if (! nochdir) {
	  if ((chdir("/")) < 0) {
		/* Log the failure */
		printf("__FUNCTION__(%s) chdir().err\n", __FUNCTION__);
		exit(EXIT_FAILURE);
	  }
  }

  /* Close out the standard file descriptors */
  if (! noclose)
  {
	int fd;

	fd = open ("/dev/null", O_RDWR, 0);
	if (fd != -1)
	{
	  dup2 (fd, STDIN_FILENO);
	  dup2 (fd, STDOUT_FILENO);
	  dup2 (fd, STDERR_FILENO);
	  if (fd > 2)
		close (fd);
	}
  }

  return sid;
}

