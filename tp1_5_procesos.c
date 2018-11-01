#include  <sys/types.h>
#include  <stdio.h>
#include  <string.h>
#include <unistd.h>

int  main(void)
{
     pid_t  pid;
     char   buf[200];

     fork();
     fork();
     pid = getpid();
     sprintf(buf, "Soy el parent|child y mi pid es %d\n", pid);
     write(1, buf, strlen(buf));

     puts(buf);

     return 1;
}
