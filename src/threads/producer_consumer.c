 #include <stdio.h>
#include <pthread.h>

int data = 0;
int ready = 0;

pthread_mutex_t lock;
pthread_cond_t condition;

void *producer(void *arg)
{
    pthread_mutex_lock(&lock);

    data = 100;
    ready = 1;

    printf("Producer created data: %d\n", data);

    pthread_cond_signal(&condition);

    pthread_mutex_unlock(&lock);

    return NULL;
}

void *consumer(void *arg)
{
    pthread_mutex_lock(&lock);

    while (ready == 0)
    {
        pthread_cond_wait(&condition, &lock);
    }

    printf("Consumer received data: %d\n", data);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&condition, NULL);

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&condition);

    return 0;
}