#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* read specified number of 256-byte records from socket
and validate them */
int prompt_and_save(char *question, unsigned char *data, int len) {
unsigned char filename[32];
int fd;
printf(question);
scanf("%s", filename);
if (strlen(filename) > 32) {
return 0;
}
unlink(filename); /* remove old file */
fd = open(filename, O_WRONLY | O_CREAT, 0666);
write(fd, data, len);
close(fd);
return 1;
}


int main ()
{
    char prompt[] = "test";
    int j =5;
    int i = prompt_and_save ("test","123",10	);
    printf ("%d", i);
    return 0;
}
