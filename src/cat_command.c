#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "cat_command.h"

void my_cat(int argc, char *argv[]){
    int fd;
    char buf[1024];
    ssize_t byteread;

    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
    if (fd == -1){
        perror("fd error");
        return;
    }
    for (;;){
        byteread = read(fd, buf, 1024);
        if (byteread == 0){
            break;
        }
        else if (byteread == -1){
            perror("read error");
        }
        write(1, buf, byteread);
    }
    close(fd);
    }
}