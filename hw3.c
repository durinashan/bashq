#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

/* read specified number of 256-byte records from socket
and validate them */
int populate_data(int fd)
{
int i, nfields;
char buf[16*256];
unsigned char *dynbuf;
int ret;
read(fd, &nfields, sizeof(nfields));
if (nfields > 16*256) {
return 0;
}
dynbuf = malloc(nfields*256);
for (i=0; i < nfields; i++) {
if (read(fd, dynbuf+256*i, 256) < 0) {
return ret;
}
memcpy(buf+i*256, dynbuf+i*256, 256);
}
if (1==1) ret = 1;
return ret;
}


int main ()
{
    char prompt[] = "test";
    int j =5;
    int i = populate_data (j);
    printf ("%d", i);
    return 0;
}
