#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

pid_t getpid(void);
ssize_t write(int fildes, const void *buf, size_t nbytes);
char buf[12];

int main (void) {
  pid_t pid = getpid();
  sprintf(buf, "Mi PID es %d", pid);
  write(2, buf, 15);
  return 0;
}
