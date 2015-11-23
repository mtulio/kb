
#ifndef SRC_DAEMON_DAEMON_H_
#define SRC_DAEMON_DAEMON_H_

int daemon_main (int argc , char *argv[]);
static void daemon_mainUsage (int status);
void daemon_end(void);
int daemon_initConfig(void);

#endif /* SRC_DAEMON_DAEMON_H_ */
