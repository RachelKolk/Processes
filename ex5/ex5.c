// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    //a buffer that will hold the incoming data that is being written
    char inbuf[MSGSIZE];
    //a two element array to hold the read[0] and write[1] file descriptors
    int p[2];

    // we establish our pipe, passing it the above array so that it gets populated by
    //the read and write file descriptors
    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    // we create our fork
    pid_t pid = fork();
    printf("pid is %d\n", pid);

    // we check to see if it's the child and if so it writes the messages
    if (pid == 0) {
        printf("I am the child...writing\n");

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }

    // if it's the parent it reads/prints the messages
    else {
        int wait = waitpid(pid, NULL, 0);

        printf("I am the parent...reading\n");

        close(p[1]);

        for (int i = 0; i < 3; i++) {
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
        printf("Done.\n"); 

    }
    
    return 0;
}
