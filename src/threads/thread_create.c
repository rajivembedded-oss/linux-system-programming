#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg)
{
    printf("Hello from the thread!\n");
    return NULL;
}

int main(void)
{
    pthread_t thread;

    if (pthread_create(&thread, NULL, threadFunction, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    pthread_join(thread, NULL);

    return 0;
}