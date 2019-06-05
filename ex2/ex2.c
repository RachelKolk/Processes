// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* fp;
    fp = fopen("text.txt", "w+");

    pid_t pid = fork();

    printf("pid is %d\n", pid);

    if (pid == 0) {
        printf("I am the child\n");
        char *child = "The child is writing this.\n";
        fwrite(child, sizeof(char), strlen(child), fp);
    } else {
        printf("I am the parent\n");
        char *parent = "The parent is writing this.\n";
        fwrite(parent, sizeof(char), strlen(parent), fp);
    }

    fclose(fp);
    
    return 0;
}
