#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int sourceFd;
    int destFd;
    char buffer[1024];
    ssize_t bytesRead;

    sourceFd = open("input.txt", O_RDONLY);

    if (sourceFd == -1)
    {
        perror("Error opening input file");
        return 1;
    }

    destFd = open("output.txt",
                  O_WRONLY | O_CREAT | O_TRUNC,
                  0644);

    if (destFd == -1)
    {
        perror("Error creating output file");
        close(sourceFd);
        return 1;
    }

    while ((bytesRead = read(sourceFd, buffer, sizeof(buffer))) > 0)
    {
        if (write(destFd, buffer, bytesRead) != bytesRead)
        {
            perror("Error writing output file");
            close(sourceFd);
            close(destFd);
            return 1;
        }
    }

    close(sourceFd);
    close(destFd);

    printf("File copied successfully!\n");

    return 0;
}