#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

pid_t getpid(void);
ssize_t write(int fildes, const void *buf, size_t nbytes);

int main (void)
{
  std::string toPrint = "Mi PID es " + getpid();
  write(1, &toPrint);
  printf ("Mi PID es %d", getpid());
  return 0;
}
