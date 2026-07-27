#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char buffer[1024];
    ssize_t bytesRead;
    int wordCount = 0;
    int inWord = 0;

    fd = open("input.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
        while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
{
    for (int i = 0; i < bytesRead; i++)
    {

    }
}
    }
if (bytesRead == -1)
{
    perror("Error reading file");
    close(fd);
    return 1;
}

close(fd);

printf("Total words: %d\n", wordCount);

return 0;
    return 0;
}