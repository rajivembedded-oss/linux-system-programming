#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg)
{
    int value = *(int *)arg;

    printf("Thread received value: %d\n", value);

    return NULL;
}

int main(void)
{
    pthread_t thread;

    int number = 100;

    pthread_create(&thread, NULL, threadFunction, &number);

    pthread_join(thread, NULL);

    return 0;
}