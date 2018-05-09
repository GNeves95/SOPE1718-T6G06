#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("** Running process %d (PGID %d) **\n", getpid(), getpgrp());

  char str[99];

  sprintf(str, "/tmp/ans%d", getpid());
  printf("%s\n", str);

  if (argc == 4)
    printf("ARGS: %s | %s | %s\n", argv[1], argv[2], argv[3]);

  sleep(1);

  mkfifo(str,0660);

  return 0;
}
