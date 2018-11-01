#include  <sys/types.h>
#include  <stdio.h>
#include  <string.h>
#include <unistd.h>

int  main(void)
{
     pid_t  pid;

     fork();
     fork();
     pid = getpid();
     printf("Soy el parent|child y mi pid es %d", pid);

return 1;
}
