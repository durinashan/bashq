
#include <stdio.h>



int enter_data()
{
        char buf[100];
        unsigned char input[80];
        int done = 0;
        int i, val;
	char prompt[] = "test";

        do {
                sprintf(buf, "%s> ", prompt);
                printf(buf);
                gets(input);
                if (strlen(input) > 79) {
                        printf("Input is too big!\n");
                        return 0;
                }
                val = atoi(input);
                if (val > 0) {
                        struct in_addr *addr;
                        char *buf2 = malloc(val*sizeof(addr));
                        for (i = 0; i < val; i++) {
                          if (read(0, buf2, sizeof(addr)) < 0)
                                  return 0;
                        }
                        done = 1;
                }
        } while (!done);

        return val;
}

int main()
{
   // printf() displays the string inside quotation
   enter_data();
   return 0;
}
