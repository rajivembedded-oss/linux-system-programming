#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct SensorData
{
    int id;
    float temperature;
};

int main(void)
{
    int fd;
    struct SensorData sensor;
    ssize_t bytesRead;

    fd = open("data.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error opening binary file");
        return 1;
    }

    sensor.id = 1;
    sensor.temperature = 32.5;

    write(fd, &sensor, sizeof(sensor));

    close(fd);

    fd = open("data.bin", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening binary file for reading");
        return 1;
    }

    bytesRead = read(fd, &sensor, sizeof(sensor));

    if (bytesRead == -1)
    {
        perror("Error reading binary file");
        close(fd);
        return 1;
    }

    printf("Sensor ID: %d\n", sensor.id);
    printf("Temperature: %.2f\n", sensor.temperature);

    close(fd);

    return 0;
}