
#ifndef SRC_DAEMON_DAEMON_SIGNAL_H_
#define SRC_DAEMON_DAEMON_SIGNAL_H_

/* Signal handlers from this process */
void dm_signal_init (void);

static void dm_signal_SIGHUP (void);
static void dm_signal_SIGINT (void);
static void dm_signal_SIGQUIT (void);
static void dm_signal_SIGILL (void);


#endif /* SRC_DAEMON_DAEMON_SIGNAL_H_ */
