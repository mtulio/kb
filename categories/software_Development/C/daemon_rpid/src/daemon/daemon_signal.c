

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <daemon.h>
#include <daemon_stdout.h>

extern void daemon_end (void);

/**********************************************************/
/* Signal handlers from process. */

/* │SIGHUP      │  T        │  1 │ Hangup.                                            │  */
static void dm_signal_SIGHUP (void)
{
  /* Read config file */
  dm_stdout_print (" # SYSTEM signal caught: SIGHUP - Hang up (Read config)\n");
  /* Try to return to normal operation. */
}

/* │SIGINT      │  T        │  2 │ Terminal interrupt signal.                         │  */
static void dm_signal_SIGINT (void)
{
  dm_stdout_print (" # SYSTEM signal caught: SIGINT - Terminal interrupt signal.\n");

  daemon_end ();
  exit(0);
}

/* │SIGQUIT     │  A        │  3 │ Terminal quit signal.                              │  */
static void dm_signal_SIGQUIT (void)
{
  dm_stdout_print (" # SYSTEM signal caught: SIGQUIT - Terminal quit signal. \n");

  daemon_end ();
  exit(0);
}

/* │SIGILL      │  A        │  4 │ Illegal instruction.                               │  */
static void dm_signal_SIGILL (void)
{
  dm_stdout_print (" # SYSTEM signal caught: SIGILL - Illegal instruction. \n");
}

/* │SIGUSR1     │  T        │ 10 │ User-defined signal 1.                             │  */
static void dm_signal_SIGUSR1 (void)
{
  dm_stdout_print (" # SYSTEM signal caught: SIGUSR1 - User-defined signal 1. \n");
}

/* │SIGTERM     │  T        │ 15 │ Termination signal.                                │  */
static void dm_signal_SIGTERM (void)
{
  dm_stdout_print (" # SYSTEM signal caught: SIGTERM - Termination signal.  \n");

  daemon_end ();
  exit(0);
}


/**********************************************************/
/* Initialize all signals */
void dm_signal_handleAll ( int sigc, struct daemon_signal_t signals[] )
{
	int i = 0;
	struct daemon_signal_t *sig;
	char str_log[MAX_BUFF_SIZE];
	bzero(str_log, sizeof(str_log));


	/* Initialize all handles available in vector */
	while (i < sigc)
	{
	  sig = &signals[i];

	  if (signal(sig->signal, (void *)sig->handler) == SIG_ERR) {
		  sprintf(str_log, " # WARN - Can't catch signal: %d \n", sig->signal);
		  dm_stdout_print (str_log);
	  }

	  i++;
	}
}

/* Declare all signals and install it */
void dm_signal_init (void)
{
	static struct daemon_signal_t daemon_signals[] =
	{
	  { .signal = SIGHUP,  .handler = &dm_signal_SIGHUP,  },
	  { .signal = SIGINT, .handler = &dm_signal_SIGINT, },
	  { .signal = SIGQUIT,  .handler = &dm_signal_SIGQUIT,  },
	  { .signal = SIGILL, .handler = &dm_signal_SIGILL,  },
	  { .signal = SIGUSR1, .handler = &dm_signal_SIGUSR1,  },
	};

	dm_signal_handleAll (array_size(daemon_signals), daemon_signals);
}
