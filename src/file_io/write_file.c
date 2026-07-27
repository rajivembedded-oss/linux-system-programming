#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;
    char message[] = "Welcome to Linux System Programming!";

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        ssize_t bytesWritten;

bytesWritten = write(fd, message, strlen(message));

if (bytesWritten == -1)
{
    perror("Error writing to file");
    close(fd);
    return 1;
}
        perror("Error opening file");
        return 1;
        printf("Successfully wrote %zd bytes to output.txt\n", bytesWritten);
        close(fd);

return 0;
    }

    return 0;
}