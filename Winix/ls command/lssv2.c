#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [directory_name]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((dp = opendir(argv[1])) == NULL) {
        perror("Can't open directory");
        exit(EXIT_FAILURE);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    return 0;
}
