// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int r = 5;

    pid_t pid = fork();

    printf("pid is %d\n", pid);

    if (pid == 0) {
        printf("I am the child. My pid is: %d and the value of r is: %d\n", pid, r);
        r = 10;
        printf("Still the child, the value of r is now %d\n", r);
    } else {
        printf("I am the parent. My pid is: %d and the value of r is: %d\n", pid, r);
        r = 2;
        printf("Still the parent, the value of r is now %d\n", r);
    }

    return 0;
}
