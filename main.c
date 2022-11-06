#include "get_next_line.h"
#include "get_next_line.c"

int main()
{
    int fd = open("foo.txt", O_RDONLY);
    char    *s = get_next_line(fd, 5);
    printf("fd : %d\n", fd);
    // printf("%s\n",get_next_line(fd,9999));
    while (s != NULL)
    {
        printf("%s\n" , s);
        free(s);
        s = get_next_line(fd, 5);
    }
    free(s);
    return (0);

}