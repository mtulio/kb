
#ifndef SRC_INCLUDE_DAEMON_H_
#define SRC_INCLUDE_DAEMON_H_

#include <mtd_defs.h>
#include <config.h>

/* Server config file structure */
typedef struct {
	char config_file[100];
	char log_file[100];
	unsigned int max_pool_conn;
} daemon_cfg_t;


/* Max buffer size */
#define MAX_BUFF_SIZE	200
#define MAX_CONFIG_SIZE_ATTR	64
#define MAX_CONFIG_SIZE_VALUE	256

typedef struct {
	uint16_t daemon;
	uint16_t log;
} daemon_opt_t;

/* Signal struct */
struct daemon_signal_t
{
  int signal;                     /* signal number    */
  void (*handler) (void);         /* handler to call  */
};

#endif /* SRC_INCLUDE_DAEMON_H_ */
