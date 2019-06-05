// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    printf("pid is %d\n", pid);

    if (pid == 0) {
        printf("I'm the child\n");

        // // execvp() system call
        // char *myargs[2];
        // myargs[0] = "ls";
        // myargs[1] = NULL;
        // // takes in the name of file being executed and the null terminated array
        // execvp(myargs[0], myargs);


        // execv() system call
        char *myargs[2];
        myargs[0] = "ls";
        myargs[1] = NULL;
        // takes in the path of the file to be executed and the null terminated array
        execv("/bin/ls", myargs);

    } else {
        int wc = waitpid(pid, NULL, 0);
        printf("Done with exec system call.\n");
    } 

    return 0;
}
