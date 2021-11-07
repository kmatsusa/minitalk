#include "minitalk.h"


int ft_atoi(char *str)
{
    int res;
    int i;

    res = 0;
    i = 0;
    while(str[i])
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

void    send_bit(int id, size_t size, char *str)
{
    int i;
    int digit;

    i = 0;
    while(i <= size)
    {
        digit = 0;
        while (digit < 7)
        {
            if((str[i] >> digit) & 1)
                kill((pid_t)id, SIGUSR2);
            else
                kill((pid_t)id, SIGUSR1);
            digit++;
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int id;
    size_t size;

    if(argc != 3)
        return (0);
    id = ft_atoi(argv[1]);
    size = ft_strlen(argv[2]);
    send_bit(id, size, argv[2]);
    return (0);
}