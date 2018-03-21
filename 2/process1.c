#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main () {
    int pid0 = fork();
    if (pid0 > 0) { // Parent
        printf("%s %d%s", "Parent process created:", pid0, "\n");
        int pid1 = fork();
        if (pid1 > 0) { // Parent
            printf("%s %d%s", "Parent process created:", pid1, "\n");
        } else if (pid1 == 0) { // Child
            printf("%s %d%s", "Child process created:", getpid(),"\n");
        }
    } else if (pid0 == 0) { // Child
        printf("%s %d%s", "Child process created:", getpid(),"\n");
    }
    return 0;
}
