
#ifndef SRC_INCLUDE_DAEMON_H_
#define SRC_INCLUDE_DAEMON_H_

#include <defs.h>
#include <config.h>

/* Server config file structure */
typedef struct {
	char config_file[100];
	char log_file[100];
	char secret[16];
	unsigned int max_pool_conn;
} daemon_cfg_t;

/* Return codes */
#define EXIT_ERR	-1
#define EXIT_OK		0

#define RET_OK			EXIT_OK
#define RET_ERR			1
#define RET_NOTFOUND	10
#define RET_IOERR		20

/* Daemon error */
#define RET_ERR_DM01	-20
#define RET_ERR_DM02	-21

/* Max buffer size */
#define MAX_BUFF_SIZE	200
#define MAX_CONFIG_SIZE_ATTR	64
#define MAX_CONFIG_SIZE_VALUE	256

#define FLAG_DISABLED	0
#define FLAG_ENABLED	1

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
