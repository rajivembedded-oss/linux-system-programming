#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main(void)
{
    int fd;

    /* Open UART device */
    fd = open("/dev/ttyS0", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    struct termios tty;

    /* Get current UART settings */
    if (tcgetattr(fd, &tty) != 0)
    {
        perror("tcgetattr");
        close(fd);
        return 1;
    }

    /* Set baud rate */
    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    /* Configure UART: 8 data bits, no parity, 1 stop bit */
    tty.c_cflag &= ~PARENB;     // Disable parity
    tty.c_cflag &= ~CSTOPB;     // One stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;         // 8 data bits
    tty.c_cflag |= CREAD | CLOCAL;

    /* Apply the settings */
    if (tcsetattr(fd, TCSANOW, &tty) != 0)
    {
        perror("tcsetattr");
        close(fd);
        return 1;
    }

    printf("UART configured successfully.\n");

    close(fd);

    return 0;
}