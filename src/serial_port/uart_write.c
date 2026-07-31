#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;
    const char *message = "Hello UART!\n";

    /* Open UART device */
    fd = open("/dev/ttyS0", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    /* Write data to UART */
    if (write(fd, message, strlen(message)) == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Message sent successfully.\n");

    close(fd);

    return 0;
}