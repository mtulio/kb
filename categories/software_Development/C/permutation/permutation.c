#include <string.h>

#include "list_linked.h"
#include "permutation.h"

/* Set permutation value from 's_buf' and insert to list 'list_root' */
int setPermutation_insertList_int(char *s_buff, int pos_ctrl, struct list_node *list_root)
{
	char s_tmp[2] = " ";
	char s_buff_new[strlen(s_buff)];

	memcpy(s_buff_new, s_buff, sizeof(s_buff));

	for (int pos=0; pos<strlen(s_buff_new); pos++) {
		// Renew buffer
		memcpy(s_buff_new, s_buff, sizeof(s_buff));

		if (pos != pos_ctrl) {
			//swap positions
			s_tmp[0] = s_buff[pos_ctrl];
			s_buff_new[pos_ctrl]=s_buff[pos];
			s_buff_new[pos]=s_tmp[0];

			// Insert value to tree/list/vector
			//printf("([%d]:[%s]) ", pos, s_buff_new);
			list_insert_int(list_root, atoi(s_buff_new));

		}
	}
	return 0;
}
