#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (rmdir("logs") == -1)
    {
        perror("Error removing directory");
        return 1;
    }

    printf("Directory 'logs' removed successfully!\n");

    return 0;
}