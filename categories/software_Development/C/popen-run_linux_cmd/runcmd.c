#include<stdlib.h>
#include<stdio.h>

/* Run an program (in this case 'ls -la') and show it in stdout */

int main(void) 
{
  FILE *fd;
  char str_cmd[1024], str_buf[1024];

  sprintf(str_cmd, "ls -la /tmp >/dev/null && echo testmt > /tmp/sysmt.log && cat /tmp/sysmt.log");
  //sprintf(str_cmd, "ls -la /tmp");

  fd = popen(str_cmd, "r");
  while (fgets(str_buf, 1024, fd) != NULL)
  printf("%s", str_buf);
	
  fclose(fd);

  exit(0);
}
