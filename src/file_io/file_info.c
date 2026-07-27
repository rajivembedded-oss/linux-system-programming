#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include <time.h>

int main(void)
{
    struct stat fileStat;

    if (stat("input.txt", &fileStat) == -1)
    {
        perror("Error getting file information");
        return 1;
    }
printf("File Permissions: %o\n", fileStat.st_mode & 0777);
    printf("File Size: %ld bytes\n", fileStat.st_size);

    printf("File Permissions: %o\n", fileStat.st_mode & 0777);
    if (S_ISREG(fileStat.st_mode))
{
    printf("File Type: Regular file\n");
printf("Last Modified: %s", ctime(&fileStat.st_mtime));
}
else if (S_ISDIR(fileStat.st_mode))
{
    printf("File Type: Directory\n");
}
else if (S_ISLNK(fileStat.st_mode))
{
    printf("File Type: Symbolic link\n");
}
    return 0;
}