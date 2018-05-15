#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Not technically required, but needed on some UNIX distributions */
#include <sys/types.h>
#include <sys/stat.h>

int get_input(unsigned char *prompt)
{
        unsigned char question[100];
        unsigned char input[80];
        char *addrbuf;
        struct in_addr *addr;
        int i, val, fd;
        sprintf(question, "%s> ", prompt);
        printf(question);
        gets(input);
        if (strlen(input) > 79) {
                printf("Input is too long!\n");
                return 0;
        }
        val = atoi(input);
        if (val > 0) {
                if (access ("/tmp/mydata", O_RDWR)) {
                        fd = open("/tmp/mydata", O_RDWR);
                        addrbuf = malloc(val*sizeof(addr));
                        for (i = 0; i < val; i++) {
                                if (read(0, addrbuf, sizeof(*addr)) < 0)
                                        return 0;
                                write(fd, addrbuf, sizeof(addrbuf));
                        }
                        close(fd);
                } else {
                        printf("You do can not write to output file\n");
                        return 0;
                }
        }
        return val;
}

int main()
{
   int i;
   unsigned char prompt[] = "test";
   i = get_input(prompt);
   printf("%d",i);
   return 0;
}
