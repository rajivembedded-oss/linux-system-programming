#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(void)
{
if (mkdir("logs", 0755) == -1)
{
    perror("Error creating directory");
    return 1;
}

printf("Directory 'logs' created successfully!\n");

return 0;
    return 0;
}