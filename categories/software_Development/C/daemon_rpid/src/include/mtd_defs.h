#ifndef SRC_INCLUDE_DEFS_H_
#define SRC_INCLUDE_DEFS_H_

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

/* FLAGS */
#define FLAG_DISABLED	0
#define FLAG_ENABLED	1

/* Types */
typedef unsigned short int	uint16_t;

/* MACROS */
#define array_size(ar) (sizeof(ar) / sizeof(ar[0]))

#endif /* SRC_INCLUDE_DEFS_H_ */
