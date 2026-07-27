#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());

        sleep(2);

        printf("Child Finished\n");
    }
    else
    {
        wait(NULL);

        printf("Parent Process\n");
        printf("Child completed.\n");
    }

    return 0;
}