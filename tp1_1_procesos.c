#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

pid_t getpid(void);
ssize_t write(int fildes, const void *buf, size_t nbytes);

int main (void) {
  printf ("Mi PID es %d", getpid());
  return 0;
}
