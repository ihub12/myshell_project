#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "exec_command.h"
#include <sys/wait.h>

void my_exec(char* argc, char* argv[]){
    pid_t pid = fork();

if (pid == 0){
    execvp(argc, argv);
}
else {
    wait(NULL);
}
}