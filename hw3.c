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
if (validate_data(buf, nfields) ret = 1;
return ret;
}
