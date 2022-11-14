#include "get_next_line.h"
#include <time.h>   // for time()
#include <stdlib.h> // for rand() & srand()

// char *change_name(void)
// {

//     srand (time (NULL)); // define a seed for the random number generator
//     const char ALLOWED[] = "abcdefghijklmnopqrstuvwxyz1234567890";
//     char *random = malloc(sizeof(char) * 6);
//     int i = 0;
//     int c = 0;
//     int nbAllowed = sizeof(ALLOWED) - 1;
//     for(i = 0; i < 5; i++) 
//     {
//         c = rand() % nbAllowed ;
//         random[i] = ALLOWED[c];
//     }
//     random[5] = '\0';
//     return random;
// }
static int      ft_get_length_number(int n)
{
        int     i;

        i = 0;
        if (n <= 0)
        {
                n *= (-1);
                i++;
        }
        while (n)
        {
                n /= 10;
                i++;
        }
        return (i);
}

char    *ft_itoa(int n)
{
        long            nbr;
        int             length;
        char            *numbers;

        nbr = n;
        length = ft_get_length_number(n);
        numbers = (char *)malloc(sizeof(char) * length + 1);
        if (!numbers)
                return (NULL);
        if (n == 0)
                numbers[0] = '0';
        numbers[length] = '\0';
        length--;
        if (nbr < 0)
        {
                numbers[0] = '-';
                nbr = nbr * (-1);
        }
        while (nbr)
        {
                numbers[length] = (nbr % 10) + '0';
                nbr = nbr / 10;
                length --;
        }
        return (numbers);
}
int main()
{
    int fd;
    int i = 0;
    char s[10242];
    char c[50];

    strcpy(s, "p");
    
    while (i < 9418)
    {
        strcpy(c , ft_itoa(i));
        strcpy(s, "p");
        strcat(s, c);
        fd = open(s, O_CREAT | O_RDWR, 0777);
        printf("%d\n",fd);
        i++;
    }
    return 0;
}