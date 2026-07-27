#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

FILE *logFile;

pthread_mutex_t logLock;


void writeLog(const char *message)
{
    pthread_mutex_lock(&logLock);

    fprintf(logFile, "%s\n", message);
    fflush(logFile);

    pthread_mutex_unlock(&logLock);
}


void *sensorThread(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        writeLog("Sensor data received");

        sleep(1);
    }

    return NULL;
}


void *networkThread(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        writeLog("Network packet processed");

        sleep(1);
    }

    return NULL;
}


int main(void)
{
    pthread_t sensor;
    pthread_t network;


    logFile = fopen("system.log", "w");

    if(logFile == NULL)
    {
        perror("File open error");
        return 1;
    }


    pthread_mutex_init(&logLock, NULL);


    pthread_create(&sensor, NULL, sensorThread, NULL);

    pthread_create(&network, NULL, networkThread, NULL);


    pthread_join(sensor, NULL);

    pthread_join(network, NULL);


    pthread_mutex_destroy(&logLock);


    fclose(logFile);


    printf("Logging completed\n");


    return 0;
}