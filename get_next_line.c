#include "get_next_line.h"

int is_there_newline(char *str, int *len)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            *len = i;
            return 1;
        }
        i++;
    }
    return 0;
}

char *get_next_line(int fd, size_t buffer_size)
{
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * buffer_size);
    static char *temp;
    char *line;
    int nbytes_read = 1;
    int newline_index = 0;
    if (!temp)
        temp = ft_strdup("");
    // printf("Ma static Ma ZAbi had temp :%s:\n",temp);
    line = ft_strdup("");
    if (fd < 0 || buffer_size <= 0 || read(fd, &temp, 0) < 0)
        return (NULL);
    while (nbytes_read != 0)
    {
        nbytes_read = read(fd, buffer, buffer_size);
        buffer[nbytes_read] = '\0';
        // printf("the buffer read : *%s*\n",buffer);
        //  check the string read for a new line
        buffer = ft_strjoin(temp, buffer);
        // printf("the buffer read after join with temp : ==%s==\n",buffer);
        if (is_there_newline(buffer, &newline_index))
        {
            line = ft_substr(buffer, 0, newline_index + 1);                              // + 1 to include the \n "before \n"
            temp = ft_substr(buffer, newline_index + 1, strlen(buffer) - newline_index); // "after \n" + 1 to exclude \n
            // printf("after new line  temp :%s:\n",temp);
            return line;
        }
        else
        {
            temp = ft_strdup(buffer);
            // printf("the temp reserved for next call : \"%s\"\n",temp);
        }
    }
    return (temp);
}

int main()
{
    int fd = open("foo.txt", O_RDONLY);
    printf("fd : %d\n", fd);
    // printf("%s\n",get_next_line(fd,9999));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
        printf("%s\n", get_next_line(fd, 100));
        printf("%s\n", get_next_line(fd, 100));
        printf("%s\n", get_next_line(fd, 100));
        printf("%s\n", get_next_line(fd, 100));
        printf("%s\n", get_next_line(fd, 100));
        printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
    printf("%s\n", get_next_line(fd, 100));
}