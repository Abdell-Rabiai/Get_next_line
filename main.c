#include "get_next_line.h"
#include "get_next_line.c"

int main()
{
    int fd = open("foo.txt", O_RDONLY);
    printf("fd : %d\n", fd);
    char *s = get_next_line(fd);
    free(s);
    while (s)
    {
        puts(s);
        s = get_next_line(fd);
        free(s);
    }
}