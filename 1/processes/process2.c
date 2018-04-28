#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main () {
    pid_t root_pid = getpid();
    pid_t pid = getpid();
    pid_t child_pid;

    printf("=> Root with id %d\n", root_pid);
    for (uint i = 0; i < 2; ++i) {
        pid = fork();
        if (pid > 0) {
            printf("- Process %d created %d\n", getpid(), pid);
            while(wait(NULL) > 0);
        } else { // First child level
            printf("-- Child process with ID: %d created by %d:\n", getpid(), getppid());
            for (uint j = 0; j < 3; ++j) {
                child_pid = fork();
                if (child_pid > 0) {
                    while(wait(NULL) > 0);
                } else  {
                    printf("---- Process %d with father %d\n", getpid(), getppid());
                    break;
                }
            }
            break;
        }
    }

    if (getpid() == root_pid) {
        printf("ENDED MAIN PROCESS\n");
    } else {
        printf(" CHILD PROCESS %d ENDED\n", getpid());
        sleep(1);
    }
    return 0;
}
