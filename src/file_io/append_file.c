#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;
    char message[] = "New log entry added\n";

    fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        perror("Error opening log file");
        return 1;
    }

    if (write(fd, message, strlen(message)) == -1)
    {
        perror("Error writing to log file");
        close(fd);
        return 1;
    }
close(fd);

printf("Log entry added successfully!\n");

    return 0;close(fd);

printf("Log entry added successfully!\n");

return 0;
}