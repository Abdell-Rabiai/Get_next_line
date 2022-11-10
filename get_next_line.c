#include "get_next_line.h"
#include "get_next_line_utils.c"

int is_there_newline(char *str, int *newline)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            *newline = i;
            return 1;
        }
        i++;
    }
    return 0;
}

char *read_file(int fd, char *saved_string)
{
    char *buffer;
    int nbytes;
    int newline_index;

    newline_index = 0;
    nbytes = 1;
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while (!is_there_newline(saved_string,&newline_index) && nbytes != 0)
    {
        nbytes = read(fd,buffer,BUFFER_SIZE);
        buffer[nbytes] = '\0';
        saved_string = ft_strjoin(saved_string, buffer);
    }
    return saved_string;
}

char *read_line(char *saved_string, int newline_index)
{
    return(ft_substr(saved_string, 0, newline_index + 1));
}

char *read_the_rest(char *saved_string, int newline_index)
{
    return(ft_substr(saved_string, newline_index + 1, ft_strlen(saved_string) - newline_index));
}

char *get_next_line(int fd)
{
    static char *saved_string;
    char *line;
    int newline_index;
    static int end;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return  (NULL);
    if(end == 1)
        return (NULL);
    if(!saved_string)
        saved_string = ft_strdup("");
    saved_string = read_file(fd, saved_string);
    if(is_there_newline(saved_string,&newline_index) && end == 0)
    {
        line = read_line(saved_string,newline_index);
        saved_string = read_the_rest(saved_string,newline_index);
    }
    else
    {
        line = saved_string;
        end = 1;
    }
    return (line);
}

// int main()
// {
//     int fd = open("foo.txt", O_RDONLY);
//     printf("fd : %d\n", fd);
//     // printf("%s\n",get_next_line(fd,9999));
//     char *s = get_next_line(fd);
//     while (s)
//     {
//         puts(s);
//         s = get_next_line(fd);
//     }
//     printf("%p\n",get_next_line(fd));
// }