#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int url_encode_and_validate(void) {
char input[100], encoded[200];
int ret = 0;
int i, j;
gets(input);
if (strlen(input) > 100) {
return 0;
}
j = 0;
for (i=0; i<strlen(input); i++) {
encoded[j++] = ’%’;
encoded[j++] = hex_char((input[i] >> 4) & 15);
encoded[j++] = hex_char(input[i] & 15);
}
encoded[j] = 0;
if (validate(encoded)) ret = 1;
return ret;
}

int main ()
{
    char prompt[] = "test";
    int j =5;
    int i = url_encode_and_validate;
    printf ("%d", i);
    return 0;
}
