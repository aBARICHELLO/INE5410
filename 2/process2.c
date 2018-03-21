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
        if (pid > 0) {
            pid = fork();
            if (pid > 0) {
                printf("- Process %d created %d\n", getpid(), pid);
                wait((int*)-1);
            } else if (pid == 0) {
                printf("-- Child process with ID: %d created:\n", getpid());
                for (uint i = 0; i < 2; ++i) {
                    child_pid = fork();
                    if (child_pid > 0) {
                        wait((int*)-1);
                    } else if (child_pid == 0) {
                        printf("---- Process %d\n", getpid());
                        sleep(1);
                    }
                }
            }
        }
    }

    if (getpid() == root_pid) {
        printf("ENDED MAIN PROCESS\n");
    } else {
        printf("CHILD PROCESS Nº%d ENDED\n", getpid());
    }
}
