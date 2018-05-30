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
